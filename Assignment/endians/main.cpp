#include <iostream>
#include <fstream>
#include <sstream>
#include "string"

using namespace std;

// helper method to represent values as HEX
string to_hex(unsigned short x){
    stringstream s;
    s << hex << x;
    return s.str();
}

// helper method used for testing and showing values in console
int hex_to_string(string hexStr) {
    stringstream s;
    int x;
    s << hex << hexStr;
    s >> x;
    return x;
}

// method that converts decimal values to 16 bit representation
string bin_str16(unsigned short n) {
    string result = "";
    int count = 0;
    for(int i = 1; i <= 32768; i *= 2) {
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

// method used to represent 8bit long values after extraction
string bin_str8(unsigned short n) {
    string result = "";
    int count = 0;
    for(int i = 1; i <= 128; i *= 2) {
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

// the main method takes in the original value and masks it and returns LittleEndian bits
int toLittleEndian(unsigned short big) {
    short little = (((big & 0xFF) << 8) | ((big & 0xFF00)>>8));
    return little;
}

// method used to mask the LittleEndian with the wished values
unsigned char extractToChar(unsigned short value, int begin, int end) {
    unsigned short mask = (1 << (end - begin)) - 1;
    return (value >> begin) & mask;
}

int main() {
    unsigned short a;
    unsigned short b;
    unsigned char c;
    ifstream infile;
    infile.open("test.dat");
    fstream outFile, outFile1;
    outFile.open("littleEndian.dat", ios::out);
    outFile1.open("8bitExtract.dat", ios::out);

    string line;
    while (getline(infile, line)) {
        istringstream iss(line);
        if (!(iss >> a)) {
            break;
        }
        cout << "Input " << bin_str16(a) << " | Value: " << a << " | Big Endian HEX : " << to_hex(a)<< endl;
        outFile << "Input " << bin_str16(a) << " | Value: " << a << " | Big Endian HEX : " << to_hex(a)<< endl;
        b = toLittleEndian(a);
        cout << "Outpu " <<  bin_str16(b) << " | Value: " << b << " | Little Endian Hex : " << to_hex(b)<< endl;
        outFile << "Outpu " <<  bin_str16(b) << " | Value: " << b << " | Little Endian Hex : " << to_hex(b)<< endl;
        c = extractToChar(b, 4, 12);
        cout << "Extra " << bin_str8(c) << " Size: " << sizeof(c) << "| Value: " << hex_to_string(to_hex(c)) << " | Hex : " << to_hex(c) << endl;
        outFile1 << "Extra " << bin_str8(c) << " Size: " << sizeof(c) << "| Value: " << hex_to_string(to_hex(c)) << " | Hex : " << to_hex(c) << endl;
        outFile << endl;
        cout << endl;
    }
    outFile.close();
    outFile1.close();
    infile.close();

    return 0;
}
