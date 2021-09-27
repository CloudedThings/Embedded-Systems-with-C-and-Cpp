#include <iostream>

using namespace std;

int main() {
    int x = 33;
    int y = 23;

    auto f = [z = 100](auto a, auto b) mutable {

        return a + b + z;
    };

    auto f2 = [z = 100]() mutable {

        return z++;
    };

    while(f2() < 120) {
        cout << "Inne" << endl;
    }
    cout << "Done" << endl;
    return 0;
}
