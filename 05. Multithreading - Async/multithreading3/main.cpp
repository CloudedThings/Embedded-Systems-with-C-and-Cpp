#include <iostream>
#include "thread"
#include "string"
#include "chrono"
#include "functional"

using namespace std;

class ThreadWrapper {
public:
    ThreadWrapper(const function<void()> & f, string n) : _t(new thread(f)), _name(move(n)){}
    ~ThreadWrapper(){
        if(_t->joinable()){
            _t->join();
            cout << _name << " joined " << endl;
        }
        delete _t;
    }
private:
    string _name;
    thread* _t;
};

void worker(){
    cout << "Worker 1" << endl;
    this_thread::sleep_for(chrono::seconds(2));
}

int main() {
    cout << "Starting first thread " << endl;
    {
        ThreadWrapper t1(worker,"ONE");
        ThreadWrapper t2(worker,"TWO");
        ThreadWrapper t3(worker,"THREE");
    }
    cout << "Starting second thread " << endl;
    ThreadWrapper t2([]{
        cout << "Worker 2" << endl;
        this_thread::sleep_for(chrono::seconds(2));
    }, "Two");

    cout << "Processed finished! " << endl;

    return 0;
}
