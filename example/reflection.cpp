#include <iostream>
#include "Reflection.hpp"

using namespace std;
struct Test
{
    int a;
    std::string b;
};

MAKE_REFLECTION(Test, a, b);


int main()
{
    Test t{42, "Hello, World!"};
    cout << "#0:" << t.a << " " << t.b << endl;

    auto test_reflection = GetReflection(t);
    cout << "#1: type name->" << test_reflection.type_name << endl;

    test_reflection.set_a(10);
    test_reflection.set_b("set by set_xxx function");
    cout << "#2:" << test_reflection.get_a() << " " << test_reflection.get_b() << endl;
    cout << "#3:" << t.a << " " << t.b << endl;

    test_reflection.SetValue("a", 20);
    test_reflection.SetValue("b", string("set by SetValue function")); // SetValue need the same type of member
    cout << "#4:" << t.a << " " << t.b << endl;

    test_reflection.SetValue("a", "hello"); // this will not change the value
    test_reflection.SetValue("b", "hello"); // this will not change the value
    cout << "#5:" << t.a << " " << t.b << endl;
    return 0;
}