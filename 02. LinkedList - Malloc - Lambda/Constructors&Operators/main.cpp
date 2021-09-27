#include <iostream>
#include "memory"

using namespace  std;

class TestClass
{
public:
    TestClass() : x_(0) {
        cout << "Default constructor. x = " << x_ << endl;
    }

    TestClass(int x) : x_(x) {
        cout << "Single arg constructor. x = " << x << endl;
    }

    TestClass(const TestClass &other) : x_(other.x_) {
        cout << "Copy constructor. x = " << x_ << endl;
    }

    TestClass & operator = (const TestClass &other) {
        x_ = other.x_;
        cout << "Copy assignment. x = " << x_ << endl;
        return *this;
    }

    ~TestClass() {
        cout << "Destructing object. x = " << x_ << endl;
    }

    int getX() {
        return x_;
    }

private:
    int x_;
};

int main() {
//    Raw pointers
//    TestClass *t1 = new TestClass();
//    TestClass *t2;
//    t2 = t1;
//    cout << t1->getX() << endl;
//    delete t1;
//    t1 = nullptr;
//    cout << t1->getX() << endl;
    cout << "First" << endl;
    {
        unique_ptr<TestClass> u_ptr = make_unique<TestClass>(1);
        cout << u_ptr->getX() << endl;
//        unique_ptr<TestClass> u_ptr2 = u_ptr;
        shared_ptr<TestClass> sh_ptr(new TestClass(2));
        shared_ptr<TestClass> sh_ptr2;
        sh_ptr = sh_ptr2;
    }
//    RAII
    {
        auto sh_ptr = make_shared<TestClass>(3);
        auto sh_pt2 = sh_ptr;
    }
    cout << "Second" << endl;

    return 0;
}
