#include <iostream>
#include <algorithm>

using namespace std;
struct Process {
    int Pid;
    int AT;
    int BT;
    int CT;
    int WT;
    int TAT;
};
bool compare_AT(Process p1, Process p2)
{
    return p1.AT < p2.AT;
}
void print_table(Process processes[], int n, float avg_WT, float avg_TAT)
{
    cout << "Pid\tAT\tBT\tCT\tWT\tTAT" << endl;
    for (int i = 0; i < n; i++) {
        cout << processes[i].Pid << "\t" << processes[i].AT << "\t" << processes[i].BT << "\t" << processes[i].CT << "\t" << processes[i].WT << "\t" << processes[i].TAT << endl;
    }
    cout << "Average WT is : " << avg_WT << endl;
    cout << "Average TAT is : " << avg_TAT << endl;
}
void fcfs_scheduling(Process processes[], int n)
{
    int current_time = 0;
    float total_WT = 0, total_TAT = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].AT)
        {
            current_time = processes[i].AT;
        }
        current_time += processes[i].BT;
        processes[i].CT = current_time;
        processes[i].TAT = processes[i].CT - processes[i].AT;
        processes[i].WT = processes[i].TAT - processes[i].BT;
        total_WT += processes[i].WT;
        total_TAT += processes[i].TAT;
    }
    float avg_WT = total_WT / n;
    float avg_TAT = total_TAT / n;
    print_table(processes, n, avg_WT, avg_TAT);
}
int main()
{
    int n;
    cout << "Enter the no of processes: ";
    cin >> n;
    Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].Pid = i + 1;
        cout << "Enter the at of process " << i + 1 << ": ";
        cin >> processes[i].AT;
        cout << "Enter the bt of process " << i + 1 << ": ";
        cin >> processes[i].BT;
    }
    sort(processes, processes + n, compare_AT);
    fcfs_scheduling(processes, n);
    return 0;
}
