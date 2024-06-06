# GUtil
some cpp code snippet

## compiler 
- XCode 15.3

## Simple Reflection
[example](./example/reflection.cpp)
- MAKE_REFLECTION
- reflection.set_xxx(value)
- reflection.get_xxx()
- SetValue(member_name, value) [**the value type should be same of member type**]
```cpp
struct Test {
    int a;
    std::string b;
};

MAKE_REFLECTION(Test, a, b);


```
## replace std::shared_ptr
[example](./example/ref_object.cpp)

let `T` be derived from `RefObject` and then use `Ptr<T>` like a shared_ptr, it's helpful if you want to implement a gc system with a base object
- Ptr<T> 
- Attach/Detach