# GUtil
some cpp code snippet


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
