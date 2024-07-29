#include <iostream>
#include <format>
#include <string>
#include "gutil/trial_util.hpp"

using namespace std;

class Test {};
class Test2 {
public:
    using value_type = int;
};

class Test3 {
public:
    void begin() {}
    void end() {}
};

int main() {
    cout << is_container<std::vector<int>>::value << endl;
    cout << is_container<Test>::value << endl;
    cout << is_container<Test2>::value << endl;
    cout << is_container<Test3>::value << endl;


    return 0;
}