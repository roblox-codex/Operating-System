#include <iostream>
using namespace std;

struct proc
{
    int no, at, bt, it, ct, tat, wt;
};

struct proc read(int i)
{
    struct proc p;
    cout << "\nProcess No: " << i << endl;
    p.no = i;
    cout << "Enter Arrival Time: ";
    cin >> p.at;
    cout << "Enter Burst Time: ";
    cin >> p.bt;
    return p;
}

int main()
{
    int n, j, min = 0;
    float avgtat = 0, avgwt = 0;
    struct proc p[10], temp;
    cout << "<--SJF Scheduling Algorithm (Non-Preemptive)-->\n";
    cout << "Enter Number of Processes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
        p[i] = read(i + 1);
    for (int i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (p[j].at > p[j + 1].at)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
    for (j = 1; j < n && p[j].at == p[0].at; j++)
        if (p[j].bt < p[min].bt)
            min = j;
    temp = p[0];
    p[0] = p[min];
    p[min] = temp;
    p[0].it = p[0].at;
    p[0].ct = p[0].it + p[0].bt;
    cout << "\nGantt Chart:\n";
    cout << "-------------------------\n";
    cout << "| P" << p[0].no << " ";
    for (int i = 1; i < n; i++)
    {
        for (j = i + 1, min = i; j < n && p[j].at <= p[i - 1].ct; j++)
            if (p[j].bt < p[min].bt)
                min = j;
        temp = p[i];
        p[i] = p[min];
        p[min] = temp;
        if (p[i].at <= p[i - 1].ct)
            p[i].it = p[i - 1].ct;
        else
            p[i].it = p[i].at;
        p[i].ct = p[i].it + p[i].bt;
        cout << "| P" << p[i].no << " ";
    }
    cout << "|\n";
    cout << "-------------------------\n";
    cout << "\nProcess\t\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
        avgtat += p[i].tat;
        p[i].wt = p[i].tat - p[i].bt;
        avgwt += p[i].wt;
        cout << "P" << p[i].no << "\t\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << endl;
    }
    avgtat /= n, avgwt /= n;
    cout << "\nAverage TurnAroundTime=" << avgtat << endl;
    cout << "Average WaitingTime=" << avgwt << endl;
    return 0;
}
