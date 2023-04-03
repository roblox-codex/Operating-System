#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Process {
    int pid;
    int at;
    int bt;
    int priority;
    int ct;
    int wt;
    int tat;
};

bool cmp(Process a, Process b) {
    if (a.priority != b.priority)
        return a.priority > b.priority;
    else
        return a.at < b.at;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    
    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time, burst time, priority for process " << i+1 << ": ";
        cin >> processes[i].at >> processes[i].bt >> processes[i].priority;
        processes[i].pid = i+1;
    }

    sort(processes.begin(), processes.end(), cmp);

    int time = 0, total_wt = 0, total_tat = 0;
    double cpu_utilization = 0;

    for (int i = 0; i < n; i++) {
        if (time < processes[i].at) {
            time = processes[i].at;
        }
        processes[i].ct = time + processes[i].bt;
        processes[i].tat = processes[i].ct - processes[i].at;
        processes[i].wt = processes[i].tat - processes[i].bt;
        total_wt += processes[i].wt;
        total_tat += processes[i].tat;
        cpu_utilization += processes[i].bt;
        time = processes[i].ct;
    }

    double avg_wt = (double)total_wt / n;
    double avg_tat = (double)total_tat / n;
    cpu_utilization /= time;
    double throughput = (double)n / time;

    cout << "PID\tAT\tBT\tPriority\tCT\tWT\tTAT" << endl;
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t" << processes[i].at << "\t" << processes[i].bt << "\t" 
             << processes[i].priority << "\t\t" << processes[i].ct << "\t" << processes[i].wt 
             << "\t" << processes[i].tat << endl;
    }

    cout << "Average Waiting Time: " << avg_wt << endl;
    cout << "CPU Utilization: " << cpu_utilization << endl;
    cout << "Average Turnaround Time: " << avg_tat << endl;
    cout << "Throughput: " << throughput << endl;

    return 0;
}
