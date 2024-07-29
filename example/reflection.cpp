#include <iostream>
#include "gutil/reflection.hpp"

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

    test_reflection.SetValue("b", string("use GetValue<> function")); // this will not change the value
    cout << "#6:" << test_reflection.GetValue<int>("a") << " " << test_reflection.GetValue<std::string>("b") << endl;
    
    try {
        cout << "#7:" << test_reflection.GetValue<char>("a") << " " << test_reflection.GetValue<std::string>("b") << endl;
    } catch (const std::exception& e) {
        cout << "#7 catch error: " << e.what() << endl;
    }

    try {
        cout << "#8:" << test_reflection.GetValue<int>("c") << endl;
    } catch (const std::exception& e) {
        cout << "#8 catch error: " << e.what() << endl;
    }
    return 0;
}
/* output
#0:42 Hello, World!
#1: type name->Test
#2:10 set by set_xxx function
#3:10 set by set_xxx function
#4:20 set by SetValue function
#5:20 set by SetValue function
#6:20 use GetValue<> function
#7:#7 catch error: type not match
#8:#8 catch error: field not found
*/