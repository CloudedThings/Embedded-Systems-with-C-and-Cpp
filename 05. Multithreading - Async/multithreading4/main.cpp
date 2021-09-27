#include <iostream>
#include "thread"
#include <queue>
#include "mutex"
#include "condition_variable"
#include "chrono"

using namespace std;

auto data_chunk = 0;
queue<int> data_queue;
mutex queue_mutex;
mutex data_chunk_mutex;

condition_variable data_con;

bool moreDataToPrepare() {
    return data_chunk < 20;
}

auto prepareData() {
    this_thread::sleep_for(chrono::seconds(rand() % 5 + 1));
    lock_guard<mutex> lg(data_chunk_mutex);
    return data_chunk++;
}

void dataPrepThread() {
    while(moreDataToPrepare()) {
        auto const data = prepareData();
        {
            lock_guard<mutex> lg(queue_mutex);
            data_queue.push(data);
        }
        data_con.notify_one();
    }
}

void process(int data) {
    cout << "Processing: " << data << endl;
}

bool isLastChunk(int data) {
    return data == 19;
}

void dataProcessThread() {
    while (true) {
        unique_lock<mutex> lock(queue_mutex);
        data_con.wait(lock, [] {return !data_queue.empty();});
        auto data = data_queue.front();
        data_queue.pop();
        lock.unlock();
        process(data);

        if(isLastChunk(data)) {
            break;
        }
    }
}


int main() {

    thread producer1(dataPrepThread);
    thread producer2(dataPrepThread);
    thread consumer(dataProcessThread);

    producer1.join();
    producer2.join();
    consumer.join();

    return 0;
}
