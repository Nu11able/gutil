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

#define REFLECTION_MACRO_CALL_VEC(CALL1, CALL2, CALL3, CALL4, CALL5, CALL6, CALL7, CALL8, CALL9, CALL10, CALL11, CALL12, CALL13, CALL14, CALL15, \
    CALL16, CALL17, CALL18, CALL19, CALL20, CALL21, CALL22, CALL23, CALL24, CALL25, CALL26, CALL27, CALL28, CALL29, CALL30, CALL, ...) CALL

// 加一层 为了__VA_ARGS__能够正常展开
#define REFLECTION_MACEO_PARAM_EXPAND(x) x

#define REFLECTION_TYPE_MEMBER_TYPE_MAP_0(struct_name)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) { #member_name, std::make_shared<MemberInfo<decltype(struct_name::member_name)>>(&Reflection<struct_name>::set_##member_name, &Reflection<struct_name>::get_##member_name) },
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_2(struct_name, member_name, ...)  REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name,  __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_3(struct_name, member_name, ...)  REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_2(struct_name,  __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_4(struct_name, member_name, ...)  REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_3(struct_name,  __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_5(struct_name, member_name, ...)  REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_4(struct_name,  __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_6(struct_name, member_name, ...)  REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_5(struct_name,  __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_7(struct_name, member_name, ...)  REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_6(struct_name,  __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_8(struct_name, member_name, ...)  REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_7(struct_name,  __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_9(struct_name, member_name, ...)  REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_8(struct_name,  __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_10(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_9(struct_name,  __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_11(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_10(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_12(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_11(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_13(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_12(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_14(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_13(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_15(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_14(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_16(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_15(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_17(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_16(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_18(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_17(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_19(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_18(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_20(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_19(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_21(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_20(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_22(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_21(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_23(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_22(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_24(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_23(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_25(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_24(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_26(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_25(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_27(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_26(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_28(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_27(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_29(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_28(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_TYPE_MAP_30(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_TYPE_MAP_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_TYPE_MAP_29(struct_name, __VA_ARGS__)

#define REFLECTION_TYPE_MEMBER_TYPE_MAP(struct_name, ...) \
    REFLECTION_MACRO_CONCAT(REFLECTION_TYPE_MEMBER_TYPE_MAP_, REFLECTION_TYPE_MEMBER_COUNT(__VA_ARGS__))(struct_name, __VA_ARGS__)

#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_0(struct_name) 
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) \
const decltype(struct_name::member_name)& get_##member_name() const { return this_->member_name; } \
void set_##member_name(const decltype(struct_name::member_name)& val) { this_->member_name = val; } \

#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_2(struct_name, member_name, ...)  REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name,  __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_3(struct_name, member_name, ...)  REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_2(struct_name,  __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_4(struct_name, member_name, ...)  REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_3(struct_name,  __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_5(struct_name, member_name, ...)  REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_4(struct_name,  __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_6(struct_name, member_name, ...)  REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_5(struct_name,  __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_7(struct_name, member_name, ...)  REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_6(struct_name,  __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_8(struct_name, member_name, ...)  REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_7(struct_name,  __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_9(struct_name, member_name, ...)  REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_8(struct_name,  __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_10(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_9(struct_name,  __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_11(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_10(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_12(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_11(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_13(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_12(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_14(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_13(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_15(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_14(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_16(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_15(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_17(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_16(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_18(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_17(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_19(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_18(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_20(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_19(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_21(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_20(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_22(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_21(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_23(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_22(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_24(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_23(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_25(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_24(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_26(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_25(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_27(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_26(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_28(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_27(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_29(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_28(struct_name, __VA_ARGS__)
#define REFLECTION_TYPE_MEMBER_GETTER_SETTER_30(struct_name, member_name, ...) REFLECTION_TYPE_MEMBER_GETTER_SETTER_1(struct_name, member_name) REFLECTION_TYPE_MEMBER_GETTER_SETTER_29(struct_name, __VA_ARGS__)

#define REFLECTION_TYPE_MEMBER_GETTER_SETTER(struct_name, ...) \
    REFLECTION_MACRO_CONCAT(REFLECTION_TYPE_MEMBER_GETTER_SETTER_, REFLECTION_TYPE_MEMBER_COUNT(__VA_ARGS__))(struct_name, __VA_ARGS__)

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
    REFLECTION_TYPE_MEMBER_GETTER_SETTER(struct_name, __VA_ARGS__) \
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
            REFLECTION_TYPE_MEMBER_TYPE_MAP(struct_name, __VA_ARGS__) \
        }; \
        return fieldMap_; \
    } \
};