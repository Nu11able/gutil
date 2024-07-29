#pragma once

#include <memory>

// constructor is not thread safe
template<typename T>
class Singleton {
public:
    static T& GetInstance() {
        if (!instance_) {
            instance_ = std::make_unique<T>();
        }
        return *instance_;
    }

    virtual ~Singleton() = default;

private:
    static std::unique_ptr<T> instance_;
};

template<typename T>
std::unique_ptr<T> Singleton<T>::instance_ = nullptr;
