#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

const int BUFFER_SIZE = 10;
int buffer[BUFFER_SIZE];
int in = 0, out = 0, count = 0;

mutex mtx;
condition_variable not_full_cv, not_empty_cv;

void producer(int id) {
    for (int i = 0; i < 20; i++) {
        unique_lock<mutex> lock(mtx);
        while (count == BUFFER_SIZE) {
            not_full_cv.wait(lock);
        }
        buffer[in] = i;
        in = (in + 1) % BUFFER_SIZE;
        count++;
        cout << "Producer " << id << " produced " << i << endl;
        not_empty_cv.notify_all();
    }
}

void consumer(int id) {
    for (int i = 0; i < 20; i++) {
        unique_lock<mutex> lock(mtx);
        while (count == 0) {
            not_empty_cv.wait(lock);
        }
        int data = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;
        cout << "Consumer " << id << " consumed " << data << endl;
        not_full_cv.notify_all();
    }
}

int main() {
    thread prod1(producer, 1);
    thread prod2(producer, 2);
    thread cons1(consumer, 1);
    thread cons2(consumer, 2);

    prod1.join();
    prod2.join();
    cons1.join();
    cons2.join();

    return 0;
}
