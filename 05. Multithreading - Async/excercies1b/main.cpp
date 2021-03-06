#include <iostream>
#include <future>
#include <deque>
#include <chrono>

using namespace std;


pair<int, string> func1(future<pair<int, string>>&& future_input) {
    // Hämta ut data från future_input
    int value = future_input.get().first;

    //Genererar en ny sträng bygger på den sträng ni har fått i er future
    string str = future_input.get().second + "_ver_1";
    // sleep
    this_thread::sleep_for(chrono::seconds(1));

    return make_pair(value, str);
}


pair<int, string> func2(future<pair<int, string>>&& future_input) {
    int value = future_input.get().first;

    string str = future_input.get().second + "_ver_2";

    this_thread::sleep_for(chrono::seconds(1));

    return make_pair(value, str);
}



//
void visualize(future<pair<int, string>> && future_input,
              const chrono::time_point<chrono::high_resolution_clock>& start_time,
              atomic<unsigned long>& current_index) {
    // Get int from future_input i en variabel som heter this_idx
    int this_idx = future_input.get().first;

    while(this_idx != current_index.load()) {
        //sleep for 1 microsecond
        this_thread::sleep_for(chrono::microseconds(1));
    }

    // Skriv ut:
    // Sample <this_idx> output: <strängen från future_input> finished at <tiden som gått sedan appen startade>
    cout << "Sample index is " << this_idx << " output: " << future_input.get().second
         << " finished at "  << endl;
    // sov i en sekund
    this_thread::sleep_for(chrono::seconds(1));

    current_index.store(this_idx + 1);
}

int main() {
    // Capture the time the app starts
    const auto start_time = chrono::high_resolution_clock::now();

    // Explicitly specify the number of processors to use, except for the visualizer
    int pipeline_dept = 2;


    deque<future<void>> visualize_futures;


    atomic<unsigned long> current_idx {0};

    for (int idx = 0; idx < 100; idx++) {
        auto input_str = string("input_str_") + to_string(idx);

        promise<pair<int, string>> promise_0;
        auto future_0 = promise_0.get_future();

        promise_0.set_value(make_pair(idx, input_str));

        auto future_1 = async(launch::async, &func1, move(future_0));
        auto future_2 = async(launch::async, &func2, move(future_1));


        auto future_vis = async(launch::async, &visualize, move(future_2), ref(start_time), ref(current_idx));

        visualize_futures.push_back(move(future_vis));

        if(visualize_futures.size() > pipeline_dept) {
            visualize_futures.pop_front();
        }

        cout << "Enqued sample: " << idx << endl;
    }

    cout << "Waiting to finish..." << endl;

    for(auto& fut: visualize_futures) {
        fut.get();
    }

    cout << "All done" << endl;
    return 0;
}