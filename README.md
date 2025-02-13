# GUtil
some cpp code snippet

## compiler 
- XCode 15.3
- VisualStudio2022 MSVC 19.35.32215.0

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

## ubuntu server24.04
this script helps you to install baseic dev tools
- gcc-14.2
- zlib v1.3.1
- openssl-3.4.1
- absl 20250127.0
- protobuf v29.3
- grpc v1.70.1
- boost 1.87.0
```bash
sudo sh -c "$(curl -fsSL https://raw.githubusercontent.com/Nu11able/gutil/main/devenv.sh)"
```