#include <iostream>
#include "vector"

using namespace std;

class MyClass {
public:
    MyClass() : value_(nullptr) {
        cout << "Default constructor " << endl;
    }

    MyClass(int value) : value_(new int(value)) {
        cout << "Single argument constructor wit value " << *value_ << endl;
    }

    MyClass(const MyClass &other) : value_(new int(*other.value_)) {
        cout << "Copy constructor with value " << *value_ << endl;
    }

    MyClass(MyClass &&other) : value_(nullptr) {                    // Move constructor
        swap(value_, other.value_);
        cout << "Move constructor with value " << *value_ << endl;
    }

    ~MyClass() {

        if(value_){
            cout << "Destructing object with value " << *value_ << endl;
        } else {
            cout << "Destructing object with value NULL" << endl;
        }
        delete value_;
    }

    MyClass & operator = (const MyClass &other) {
        value_ = new int(*other.value_);
        cout << "Copy assignment with value " << *value_ << endl;
        return *this;
    }

    MyClass & operator = (MyClass &&other) {
        value_ = nullptr;
        swap(value_, other.value_);
        cout << "Move assignment with value " << *value_ << endl;
        return *this;
    }

    void print() {
        if (value_) {
            cout << *value_ << endl;
        } else {
            cout << "NULL" << endl;
        }
    }

private:
    int *value_;
};

MyClass func() {
    MyClass mm(44);
    return move(mm);
}

int main() {
    MyClass m1(10);
    MyClass m2 = func();

    return 0;
}
