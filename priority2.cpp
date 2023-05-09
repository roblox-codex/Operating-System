#include<iostream>
#include<algorithm>
using namespace std;

struct Process
{
    int arrivalTime, burstTime, priority, completionTime, waitingTime, turnaroundTime;
    bool operator<(const Process &p) const
    {
        return priority < p.priority;
    }
};

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process processes[n];

    for(int i = 0; i < n; i++)
    {
        cout << "Enter arrival time of process " << i+1 << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Enter burst time of process " << i+1 << ": ";
        cin >> processes[i].burstTime;
        cout << "Enter priority of process " << i+1 << ": ";
        cin >> processes[i].priority;
    }

    sort(processes, processes+n, [](Process a, Process b) {
        if(a.arrivalTime == b.arrivalTime)
            return a.priority < b.priority;
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = 0;
    for(int i = 0; i < n; i++)
    {
        if(currentTime < processes[i].arrivalTime)
            currentTime = processes[i].arrivalTime;
        processes[i].completionTime = currentTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
        currentTime = processes[i].completionTime;
    }

    double avgWaitingTime = 0, avgTurnaroundTime = 0;
    cout << "Process\tBurst time\tArrival time\tWaiting time\tTurnaround time\tCompletion time\tPriority\n";
    for(int i = 0; i < n; i++)
    {
        cout << "P" << i+1 << "\t\t" << processes[i].burstTime << "\t\t" << processes[i].arrivalTime << "\t\t" << processes[i].waitingTime << "\t\t" << processes[i].turnaroundTime << "\t\t" << processes[i].completionTime << "\t\t" << processes[i].priority << endl;
        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
    }
    cout << "Average waiting time = " << avgWaitingTime/n << endl;
    cout << "Average turnaround time = " << avgTurnaroundTime/n << endl;

    return 0;
}
