#include <iostream>
#include "string"

using namespace std;

void process(string &arg) {                 // lvalue reference
    cout << "lvalue process " << endl;
}

void process(string &&arg) {                // rvalue reference
    cout << "rvalue process" << endl;
}

template<typename T>                        // universal reference
void logAndProcess(T &&param) {
    process(param);
}

int main() {

    string value = "Les";

    logAndProcess("hello");


    return 0;
}
