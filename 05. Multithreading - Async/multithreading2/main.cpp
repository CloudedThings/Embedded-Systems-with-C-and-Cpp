#include <iostream>
#include "thread"
#include "chrono"

using namespace std;

class Worker {
public:
    explicit Worker(string n) : _name(move(n)){};
    void operator()() {
        cout << _name << " " << this_thread::get_id() << endl;
    }
private:
    string _name;
};

void worker() {
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "Worker 1 " << this_thread::get_id() << endl;

}


int main() {

    thread func_thread(worker);

    thread lambda1_thread([]{
        this_thread::sleep_for(chrono::milliseconds(400));
        cout << "Worker 2 " << this_thread::get_id() << endl;
    });

    auto worker2 = [] {
        this_thread::sleep_for(chrono::milliseconds(600));
        cout << "Worker 3 " << this_thread::get_id() << endl;
    };

    thread lambda2_thread(worker2);

    thread functor_thread(Worker("Worker 4"));

    functor_thread.join();
    lambda2_thread.join();
    lambda1_thread.join();
    func_thread.join();

    return 0;
}
