#pragma once
#include <string>
#include <map>
#include <type_traits>
#include <memory>

template<typename T>
struct ReflectionTypeId {
    static intptr_t TypeId() {
        return reinterpret_cast<intptr_t>(&ReflectionTypeId<T>::TypeId);
    }
};

#define REFLECTION_MAX_MEMBER_COUNT 30

#define REFLECTION_TYPE_MEMBER_COUNT_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18,_19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, N, ...) N
#define REFLECTION_TYPE_MEMBER_COUNT(...) \
    REFLECTION_TYPE_MEMBER_COUNT_IMPL(__VA_ARGS__, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define REFLECTION_MACRO_CONCAT_IMPL(a, b) a##b
#define REFLECTION_MACRO_CONCAT(a, b) REFLECTION_MACRO_CONCAT_IMPL(a, b) 

#define REFLECTION_FOR_EACH(FUNC, struct_name, ...) \
    REFLECTION_MACRO_CONCAT(REFLECTION_FOR_EACH_FUNC_CALL_, REFLECTION_TYPE_MEMBER_COUNT(__VA_ARGS__))(FUNC, struct_name, __VA_ARGS__)


#define REFLECTION_FOR_EACH_FUNC_CALL_0(FUNC, struct_name)
#define REFLECTION_FOR_EACH_FUNC_CALL_1(FUNC, struct_name, member_name) FUNC(struct_name, member_name)
#define REFLECTION_FOR_EACH_FUNC_CALL_2(FUNC, struct_name, member_name, ...)  FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_1(FUNC, struct_name,  __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_3(FUNC, struct_name, member_name, ...)  FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_2(FUNC, struct_name,  __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_4(FUNC, struct_name, member_name, ...)  FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_3(FUNC, struct_name,  __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_5(FUNC, struct_name, member_name, ...)  FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_4(FUNC, struct_name,  __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_6(FUNC, struct_name, member_name, ...)  FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_5(FUNC, struct_name,  __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_7(FUNC, struct_name, member_name, ...)  FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_6(FUNC, struct_name,  __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_8(FUNC, struct_name, member_name, ...)  FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_7(FUNC, struct_name,  __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_9(FUNC, struct_name, member_name, ...)  FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_8(FUNC, struct_name,  __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_10(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_9(FUNC, struct_name,  __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_11(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_10(FUNC, struct_name, __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_12(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_11(FUNC, struct_name, __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_13(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_12(FUNC, struct_name, __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_14(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_13(FUNC, struct_name, __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_15(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_14(FUNC, struct_name, __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_16(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_15(FUNC, struct_name, __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_17(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_16(FUNC, struct_name, __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_18(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_17(FUNC, struct_name, __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_19(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_18(FUNC, struct_name, __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_20(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_19(FUNC, struct_name, __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_21(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_20(FUNC, struct_name, __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_22(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_21(FUNC, struct_name, __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_23(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_22(FUNC, struct_name, __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_24(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_23(FUNC, struct_name, __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_25(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_24(FUNC, struct_name, __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_26(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_25(FUNC, struct_name, __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_27(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_26(FUNC, struct_name, __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_28(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_27(FUNC, struct_name, __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_29(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_28(FUNC, struct_name, __VA_ARGS__)
#define REFLECTION_FOR_EACH_FUNC_CALL_30(FUNC, struct_name, member_name, ...) FUNC(struct_name, member_name) REFLECTION_FOR_EACH_FUNC_CALL_29(FUNC, struct_name, __VA_ARGS__)


#define REFLECTION_TYPE_MEMBER_TYPE_MAP(struct_name, member_name) { #member_name, std::make_shared<MemberInfo<decltype(struct_name::member_name)>>(&Reflection<struct_name>::set_##member_name, &Reflection<struct_name>::get_##member_name) },

#define REFLECTION_TYPE_MEMBER_GETTER_SETTER(struct_name, member_name) \
const decltype(struct_name::member_name)& get_##member_name() const { return this_->member_name; } \
void set_##member_name(const decltype(struct_name::member_name)& val) { this_->member_name = val; } 

template<typename T>
class Reflection {};

template<typename T>
Reflection<T> GetReflection(T& obj) {
	return Reflection<T>(obj);
}

#define MAKE_REFLECTION(struct_name, ...) \
template<> \
class Reflection<struct_name> { \
    struct BaseMemberInfo { BaseMemberInfo(intptr_t type_) : type(type_) {} intptr_t type; }; \
    using MemberMap = std::map<std::string, std::shared_ptr<BaseMemberInfo>>; \
    template<typename T> \
    using SetterFunc = void (Reflection<struct_name>::*)(const T&); \
    template<typename T> \
    using GetterFunc = const T& (Reflection<struct_name>::*)() const; \
public: \
    using MemberMapType = std::map<std::string, std::shared_ptr<BaseMemberInfo>>; \
    template<typename T> \
    struct MemberInfo : public BaseMemberInfo { \
        MemberInfo(SetterFunc<T> setter_, GetterFunc<T> getter_) : setter(setter_), getter(getter_), BaseMemberInfo(ReflectionTypeId<T>::TypeId()) {} \
        SetterFunc<T> setter = nullptr; \
        GetterFunc<T> getter = nullptr; \
    }; \
    Reflection() = delete; \
    Reflection(struct_name& obj) : this_(&obj) {} \
    struct_name* this_; \
    REFLECTION_FOR_EACH(REFLECTION_TYPE_MEMBER_GETTER_SETTER, struct_name, __VA_ARGS__) \
    template<typename T> \
    int SetValue(const std::string_view property, T&& value) { \
        auto fieldMap_ = GetFieldMap(); \
        auto it = fieldMap_.find(property.data()); \
        if (it == fieldMap_.end()) \
            return -1; \
        if (it->second->type != ReflectionTypeId<T>::TypeId()) \
            return -1; \
        auto iter = std::static_pointer_cast<MemberInfo<T>>(it->second); \
        (this->*(iter->setter))(value); \
        return 0; \
    } \
    static constexpr std::string_view type_name { #struct_name }; \
    static const MemberMapType& GetFieldMap() { \
        static MemberMapType fieldMap_ = { \
            REFLECTION_FOR_EACH(REFLECTION_TYPE_MEMBER_TYPE_MAP, struct_name, __VA_ARGS__) \
        }; \
        return fieldMap_; \
    } \
};