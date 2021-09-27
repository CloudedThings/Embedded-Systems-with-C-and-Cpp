#include <iostream>
#include "vector"

using namespace std;

class MyClass {
public:
    MyClass() : value_(nullptr) {
        cout << "Default constructor " << endl;
    }

    MyClass(int value) : value_(new int(value)) {
        cout << "Single argument constructor with value " << *value_ << endl;
    }

    MyClass(const MyClass &other) : value_(other.value_) {
        cout << "Copy constructor with value " << *value_ << endl;
    }

    MyClass(MyClass &&other) : value_(nullptr) {
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
        cout << "Copy constructor with value " << *value_ << endl;
        return *this;
    }

    MyClass & operator = (MyClass &&other) {
        value_ = nullptr;
        swap(value_, other.value_);
        cout << "Copy constructor with value " << *value_ << endl;
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

int main() {
    vector<MyClass> myVect;
    for (int i = 0; i < 100; i++) {
        myVect.push_back(MyClass(i));
    }


    return 0;
}
