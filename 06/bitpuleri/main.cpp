#include <iostream>
#include "bitset"
#include "string"

using namespace std;

string bin_str16(unsigned short n) {
    bitset<16> bs(n);
    return bs.to_string();
}

template <typename T>
string bin_str8(T n) {
    bitset<8> bs(n);
    return bs.to_string();
}

string bin_str16_2(unsigned short n) {
    string result = "";
    int count = 0;
    for(int i = 1; i <= 32768; i *= 2){
        if((n & i) == i) {
            result = "1" + result;
        } else {
            result = "0"  + result;
        }
        if (++count % 4 == 0) {
            result = " " + result;
        }
    }
    return result;
}

void test_operators(){
    unsigned short value = 20342;
    // binary bitwise and &
    cout << value << " in binary is: " << bin_str16(value) << endl;
    cout << "------------" << endl;
    cout << value << " in binary is:" << bin_str16_2(value) << endl;

//    // binary OR |
//    cout << "------------" << endl;
//    cout << (value | 8) << endl;
//
//    // binary xor (^)
//    unsigned short value1 = 8;
//    unsigned short value2 = 12;
//    cout << "------------" << endl;
//    cout << value << " in binary is:" << bin_str16_2(value1) << endl;
//    cout << value << " in binary is:" << bin_str16_2(value2) << endl;
//    cout << (value1 ^ value2) << endl;

    // right shift operator(>>)
    value = value >> 2;
    cout << value << " in binary is: " << bin_str16(value) << endl;
    auto new_value = value;
    for (int i = 0; i < 16; i++) {
        if(new_value & 1) {
            cout << "1";
        } else {
            cout << "0";
        }
        new_value >>= 1;
    }
    cout << endl;

    // left shift <<
    cout << "------------" << endl;
    cout << value << " in binary is: " << bin_str16(value) << endl;
    value = value << 2;
    cout << value << " in binary is: " << bin_str16(value) << endl;
}
template <typename T>
T toggleBit(T n, int bit) {
    return (n ^ (1 << (bit - 1)));
}

int main() {
    cout << "-----------------" << endl;
    char signed_value = -14;
    unsigned char unsigned_value = 14;
    cout << bin_str8(signed_value ) << endl;
    signed_value = toggleBit(signed_value, 7);
    cout << bin_str8(signed_value) << endl;
//    cout << bin_str8(unsigned_value) << endl;

    string bin_str = "11110010";
    unsigned short x = stoi(bin_str, nullptr, 2);
    cout << x << endl;
    string hex_str = "ac34";
    unsigned short y = stoi(hex_str, nullptr, 16);
    cout << y << endl;
    return 0;
}
