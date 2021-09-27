#include <iostream>
#include "string"

using namespace std;

class Person{
public:
    Person() : name_("No Name") {}                    // default constructor
    Person(string name) : name_(name){}                  // single argument constructor
    Person(const Person &other) : name_(other.name_) {} // Copy constructor

    ~Person(){
        cout << name_ << " was destructed" << endl;
    }

    Person& operator = (const Person &other) {          // Copy assignment operator
        name_ = other.name_;
        return *this;
    }
    string getName() {
        return name_;
    }
    void setName(string name){
        name_ = name;
    }
private:
    string name_;
};

int main() {
//    Person p1("Lisa Venison");
//    Person p2;
//    Person p3;
//    p3 = p2 = p1;
//    cout << p1.getName() << endl;
//    cout << p2.getName() << endl;
//    cout << p3.getName() << endl;
//    cout << "-------------" << endl;
//    p2.setName("Tom Sawyer");
//    p3.setName("John Doe");
//    cout << p1.getName() << endl;
//    cout << p2.getName() << endl;
//    cout << "-------------" << endl;

    Person p1("Johnny Cash");
    {
        Person p2("Fat Joe");
    }
    Person p3("Ziggy Topp");

    return 0;
}
