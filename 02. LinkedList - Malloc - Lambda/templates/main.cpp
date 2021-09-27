#include <iostream>
#include "string"

using namespace std;

template <typename T1, typename T2>
auto func (T1 a, T2 b) -> decltype(a+b){
    return a + b;
}


int main() {
    auto x = 5;
    auto y = 7.5;
    cout << func(x, y) << endl;


//    string name = "Lesio";
//    string name1 = move(name);
//    cout << "! " << name << "! " << endl;
//    cout << "! " << name1 << "! " << endl;
//    int x = 10;
//    func(move(x));
//    func(10);
    return 0;
}
