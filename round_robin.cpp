#include <iostream>

using namespace std;

int main() {
    int quantum, num_processes, i, j, total_time = 0;
    cout << "Enter time quantum: ";
    cin >> quantum;
    cout << "Enter the number of processes: ";
    cin >> num_processes;
    int burst_time[num_processes], remaining_time[num_processes];
    for (i = 0; i < num_processes; i++) {
        cout << "Enter the burst time of process " << i + 1 << ": ";
        cin >> burst_time[i];
        remaining_time[i] = burst_time[i];
    }
    cout << "\nProcess Execution Order: ";
    while (true) {
        bool all_finished = true;
        for (i = 0; i < num_processes; i++) {
            if (remaining_time[i] > 0) {
                all_finished = false;
                if (remaining_time[i] > quantum) {
                    total_time += quantum;
                    remaining_time[i] -= quantum;
                    cout << i + 1 << " ";
                } else {
                    total_time += remaining_time[i];
                    remaining_time[i] = 0;
                    cout << i + 1 << " ";
                }
            }
        }
        if (all_finished) {
            break;
        }
    }
    cout << "\nTotal Execution Time: " << total_time << endl;
    return 0;
}
