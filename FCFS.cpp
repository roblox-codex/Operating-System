#include<iostream>
#include<queue>
using namespace std;

struct process {
    int pid;
    int at;
    int bt;
};

bool operator<(const process &p1, const process &p2) {
    return p1.at > p2.at;
}

void schedule(vector<process> processes) {
    queue<process> readyQueue;
    int currentTime = 0;

    for (int i = 0; i < processes.size(); i++) {
        while (!readyQueue.empty() && currentTime < processes[i].at) {
            process p = readyQueue.front();
            readyQueue.pop();
            cout << "Process " << p.pid << " ran for " << min(p.bt, processes[i].at - currentTime) << " units." << endl;
            p.bt -= (processes[i].at - currentTime);
            currentTime = processes[i].at;
            if (p.bt > 0) {
                readyQueue.push(p);
            }
        }
        if (currentTime < processes[i].at) {
            currentTime = processes[i].at;
        }
        readyQueue.push(processes[i]);
    }

    while (!readyQueue.empty()) {
        process p = readyQueue.front();
        readyQueue.pop();
        cout << "Process " << p.pid << " ran for " << p.bt << " units." << endl;
        currentTime += p.bt;
    }
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<process> processes(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time and burst time for process " << i+1 << ": ";
        cin >> processes[i].at >> processes[i].bt;
        processes[i].pid = i+1;
    }

    sort(processes.begin(), processes.end(), [](const process &p1, const process &p2) { return p1.at < p2.at; });

    schedule(processes);

    return 0;
}
