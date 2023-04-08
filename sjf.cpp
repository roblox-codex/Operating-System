#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Process {
    int pid; // process id
    int burst_time; // burst time or execution time
    int arrival_time; // arrival time
};

bool compare(Process p1, Process p2) {
    // sort processes by arrival time and burst time
    if (p1.arrival_time == p2.arrival_time)
        return p1.burst_time < p2.burst_time;
    else
        return p1.arrival_time < p2.arrival_time;
}

void sjf(vector<Process> processes) {
    int n = processes.size();
    int current_time = 0;
    float average_waiting_time = 0, average_turnaround_time = 0;
    
    // sort processes by arrival time and burst time
    sort(processes.begin(), processes.end(), compare);
    
    // calculate waiting time and turnaround time for each process
    for (int i = 0; i < n; i++) {
        // execute process
        cout << "Process " << processes[i].pid << " is executing.\n";
        current_time += processes[i].burst_time;
        
        // calculate waiting time and turnaround time
        int waiting_time = current_time - processes[i].arrival_time - processes[i].burst_time;
        int turnaround_time = current_time - processes[i].arrival_time;
        average_waiting_time += waiting_time;
        average_turnaround_time += turnaround_time;
        
        // print process information
        cout << "Process " << processes[i].pid << " finished execution.\n";
        cout << "Waiting time: " << waiting_time << "\n";
        cout << "Turnaround time: " << turnaround_time << "\n\n";
    }
    
    // calculate average waiting time and average turnaround time
    average_waiting_time /= n;
    average_turnaround_time /= n;
    
    // calculate CPU utilization
    float total_burst_time = 0;
    for (int i = 0; i < n; i++) {
        total_burst_time += processes[i].burst_time;
    }
    float cpu_utilization = (total_burst_time / current_time) * 100;
    
    // print average waiting time, average turnaround time, and CPU utilization
    cout << "Average waiting time: " << average_waiting_time << "\n";
    cout << "Average turnaround time: " << average_turnaround_time << "\n";
    cout << "CPU utilization: " << cpu_utilization << "%\n";
}

int main() {
    // get number of processes from user
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    
    // create processes and get input from user
    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter the arrival time and burst time for process " << i+1 << ": ";
        cin >> processes[i].arrival_time >> processes[i].burst_time;
        processes[i].pid = i+1;
    }
    
    // run SJF scheduling algorithm
    sjf(processes);
    
    return 0;
}
