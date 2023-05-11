#include <iostream>
#include <thread>
#include <mutex>
#include <random>
#include <chrono>
using namespace std;
const int num_philosophers = 5;

mutex forks[num_philosophers];
mutex print_lock;

void philosopher(int id, int num_cycles, chrono::steady_clock::time_point end_time) {
    // Set up random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> wait_time(100, 1000);

    // Keep track of elapsed time
    auto start_time = chrono::steady_clock::now();

    while (chrono::steady_clock::now() < end_time) {
        // Think for a while
        this_thread::sleep_for(chrono::milliseconds(wait_time(gen)));

        // Pick up left fork
        forks[id].lock();
        print_lock.lock();
        cout << "Philosopher " << id << " picks up left fork" << endl;
        print_lock.unlock();

        // Wait for a bit to simulate picking up right fork
        this_thread::sleep_for(chrono::milliseconds(wait_time(gen)));

        // Pick up right fork
        forks[(id + 1) % num_philosophers].lock();
        print_lock.lock();
        cout << "Philosopher " << id << " picks up right fork" << endl;
        print_lock.unlock();

        // Eat for a while
        this_thread::sleep_for(chrono::milliseconds(wait_time(gen)));

        // Put down right fork
        forks[(id + 1) % num_philosophers].unlock();
        print_lock.lock();
        cout << "Philosopher " << id << " puts down right fork" << endl;
        print_lock.unlock();

        // Put down left fork
        forks[id].unlock();
        print_lock.lock();
        cout << "Philosopher " << id << " puts down left fork" << endl;
        print_lock.unlock();

        // Check if we've completed the required number of cycles
        if (--num_cycles == 0) {
            break;
        }
    }

    // Calculate elapsed time and print final message
    auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start_time);
    print_lock.lock();
    cout << "Philosopher " << id << " completed " << (num_cycles == 0 ? "all" : "some") << " cycles in " << elapsed_time.count() << " ms" << endl;
    print_lock.unlock();
}

int main() {
    // Set up timer for 1 seconds
    auto end_time = chrono::steady_clock::now() + chrono::seconds(1);

    // Create threads for each philosopher
    thread philosophers[num_philosophers];
    for (int i = 0; i < num_philosophers; i++) {
        philosophers[i] = thread(philosopher, i, 5, end_time);
    }

    // Wait for threads to finish
    for (int i = 0; i < num_philosophers; i++) {
        philosophers[i].join();
    }

    return 0;
}
