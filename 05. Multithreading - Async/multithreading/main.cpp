#include <iostream>
#include "thread"

using namespace std;

void worker(){
    cout << "Now it thread " << this_thread::get_id() << endl;
}

int main() {
    thread t1(worker);

    cout << "Main thread " << this_thread::get_id() << endl;
    t1.join();

    return 0;
}
