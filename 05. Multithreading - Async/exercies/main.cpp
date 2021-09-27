#include <iostream>
#include "future"
#include "deque"
#include "chrono"

using namespace std;

pair<int, string> func1(future<pair<int, string>>&& future_input) {
    // get data from future_input
    int value = future_input.get().first;

    //generate string from future
    string str = future_input.get().second + "_ver_1";

    //sleep
    this_thread::sleep_for(chrono::seconds(1));

    cout << "In the first func. Value is " << value << "String: " << str << endl;

    return make_pair(value, str);
}

pair<int, string> func2(future<pair<int, string>>&& future_input) {
    // do the same things as func1 but add another string
    int value = future_input.get().first;

    string str = future_input.get().second + "_ver_2";

    this_thread::sleep_for(chrono::seconds(1));

    return make_pair(value, str);
}

void visualize(future<pair<int, string>> && future_input,
               const chrono::time_point<chrono::high_resolution_clock>& start_time,
               atomic<unsigned long>& current_index) {

    // get int from future_input and assign in variable this_idx
    int this_index = future_input.get().first;

    while(this_index != current_index.load()){
        // sleep for 1 microsecond
        this_thread::sleep_for(chrono::milliseconds(1));
    }
    auto now = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::high_resolution_clock::duration(start_time - now).count();

    // Write out: "Sample"<this_idx> "output:" future_input <string> "finished at" time since app started
    cout << "Sample index is " << this_index << " output: " << future_input.get().second
    << " finished at " << elapsedTime << endl;

    // sleep for 1 second
    this_thread::sleep_for(chrono::seconds(1));

    current_index.store(this_index + 1);
}

int main() {
    // capture app start time
    const auto start_time = chrono::high_resolution_clock::now();

    // Explicitly specify the number to use, except for the visualizer
    int pipeline_dept = 2;

    deque<future<void>> visualizer_futures;

    atomic<unsigned long> current_id {0};


    for (int i = 0; i < 100; i++) {
        auto input_str = string("input_str_") + to_string(i);
        promise<pair<int, string>> promise1;
        auto future1 = promise1.get_future();

        promise1.set_value(make_pair(i, input_str));

        auto future2 = async(launch::async, &func1, move(future1));
        auto future3 = async(launch::async, &func2, move(future2));

        auto future_visual = async(launch::async, &visualize, move(future3), ref(start_time), ref(current_id));

        visualizer_futures.push_back(move(future_visual));

        if(visualizer_futures.size() > pipeline_dept) {
            visualizer_futures.pop_front();
        }

        cout << "Enqueued sample: " << i << endl;
    }

    cout << "Waiting to finish..." << endl;

    for(auto& fut: visualizer_futures) {
        fut.get();
    }
    cout << "All done!" << endl;

    return 0;
}
