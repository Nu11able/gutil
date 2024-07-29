#include <iostream>
#include <string>
#include "gutil/ref_object.hpp"

class Test : public RefObject
{
public:
    Test(std::string msg) : msg_(msg) {
        std::cout << msg << " Test::Test()" << std::endl;
    }
    ~Test() {
        std::cout << msg_ << " Test::~Test()" << std::endl;
    }

private:
    std::string msg_;
};

void Func(RefPtr<Test> ptr) {
    std::cout << "Func" << std::endl;
}

int main() {
    RefPtr<Test> ptr(new Test("obj1"));
    RefPtr<Test> ptr2 = ptr;
    std::cout << "obj1 refcount:" << ptr2->GetRefCount() << std::endl;
    RefPtr<Test> ptr_;
    ptr_.Attach(ptr2.Detach());
    std::cout << "obj1 refcount:" << ptr_->GetRefCount() << std::endl;
    std::cout << "ptr2 now is " << std::boolalpha << (bool)ptr2 << std::endl;

    Func(ptr);
    {
        std::cout << "enter scope\n";
        RefPtr<Test> temp { new Test("scope obj2") };
        RefPtr<Test> ptr { new Test("scope obj3") };
        ptr2 = ptr;
        std::cout << "leave scope\n";
    }

    return 0;
}
/* output
obj1 Test::Test()
obj1 refcount:2
obj1 refcount:2
ptr2 now is false
Func
enter scope
scope obj2 Test::Test()
scope obj3 Test::Test()
leave scope
scope obj2 Test::~Test()
scope obj3 Test::~Test()
obj1 Test::~Test()
*/