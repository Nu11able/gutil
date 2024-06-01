#pragma once
#include <atomic>

template<typename T>
class RefPtr;

class RefObject;

template<typename To, typename From>
RefPtr<To> down_cast(RefPtr<From> f) {
    return RefPtr<To>(static_cast<To*>(f.Get()));
}

/**
 * @brief Base object of reference count.
 * every subclass must implement KeyId() function, and give a unique id as keyid.
 * And also need to implement a constructor with keyid as parameter.
 */
class RefObject {
public:
    template<typename T>
    friend class RefPtr;
    friend class RefObjectManager;

    RefObject() : ref_count_(0) {
    }
    virtual ~RefObject() {}

    int GetRefCount() { return ref_count_; }

#ifdef DEBUG
    intptr_t GetObjectId() {
        return reinterpret_cast<intptr_t>(this);
    }
#endif

private:
    void AddRef() {
        ref_count_.fetch_add(1);
    }

    void Release() {
        if (ref_count_.fetch_sub(1) == 1) {
            delete this;
        }
    }

    std::atomic<uint32_t> ref_count_;
    //int time_stamp_ = 0;
};

template<typename T>
class RefPtr {
public:
    friend class RefObjectManager;

    RefPtr() : ptr_(nullptr) {}
    RefPtr(T* ptr) : ptr_(ptr) {
        if (ptr_) {
            ptr_->AddRef();
        }
    }
    RefPtr(const RefPtr& other) : ptr_(other.ptr_) {
        if (ptr_) {
            ptr_->AddRef();
        }
    }
    RefPtr(RefPtr&& other) : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }
    ~RefPtr() {
        if (ptr_) {
            ptr_->Release();
        }
    }

    RefPtr<T>& operator=(const RefPtr<T>& other) {
        if (ptr_) {
            ptr_->Release();
        }
        ptr_ = other.ptr_;
        if (ptr_) {
            ptr_->AddRef();
        }
        return *this;
    }

    RefPtr<T>& operator=(RefPtr<T>&& other) {
        if (ptr_) {
            ptr_->Release();
        }
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
        return *this;
    }

    T* operator->() const {
        return ptr_;
    }

    T* Get() const {
        return ptr_;
    }

    operator T*() const {
        return ptr_;
    }

    T& operator*() {
        return *ptr_;
    }

    operator bool() const {
        return ptr_ != nullptr;
    }

    bool operator==(const RefPtr& other) const {
        return ptr_ == other.ptr_;
    }

    bool operator!=(const RefPtr& other) const {
        return ptr_ != other.ptr_;
    }

    bool operator==(const T* other) const {
        return ptr_ == other;
    }

    bool operator!=(const T* other) const {
        return ptr_ != other;
    }

    T* Detach() {
        T* ret = ptr_;
        ptr_ = nullptr;
        return ret;
    }

    RefPtr<T>& Attach(T* t) {
        if (ptr_) {
            ptr_->Release();
        }
        ptr_ = t;
        return *this;
    }

private:
    T* ptr_ = nullptr;
};