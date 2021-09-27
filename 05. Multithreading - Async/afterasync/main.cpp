#include <iostream>
#include "chrono"
#include "string"
#include "thread"
#include "future"

using namespace std;

string fetchFromDB(string data) {
    this_thread::sleep_for(chrono::seconds(5));
    return "DB_" + data;
}

string fetchFromFile(string data) {
    this_thread::sleep_for(chrono::seconds(4));
    return "File_" + data;
}

int main() {

    auto start = chrono::system_clock::now();
    future<string> dbData = async(launch::async, fetchFromDB, "Data");
    future<string> fileData = async(launch::async, fetchFromFile, "FileData");


    cout << dbData.get() << endl;
    cout << fileData.get() << endl;

    auto end = chrono::system_clock::now();
    auto diff = chrono::duration_cast<chrono::seconds>(end - start).count();

    cout << "It took: " << diff << " seconds" << endl;


    return 0;
}
