#include <iostream>
using namespace std;

int main()
{
    int arrival_time[10], burst_time[10], temp[10];
    int i, smallest, count = 0, time, limit;
    double wait_time = 0, turnaround_time = 0, end;
    float average_waiting_time, average_turnaround_time;
    cout << "\nEnter the Total Number of Processes:\t";
    cin >> limit;
    cout << "\nEnter Details of " << limit << " Processes\n";
    for (i = 0; i < limit; i++)
    {
        cout << "\nEnter Arrival Time:\t";
        cin >> arrival_time[i];
        cout << "Enter Burst Time:\t";
        cin >> burst_time[i];
        temp[i] = burst_time[i];
    }
    burst_time[9] = 9999;
    for (time = 0; count != limit; time++)
    {
        smallest = 9;
        for (i = 0; i < limit; i++)
        {
            if (arrival_time[i] <= time && burst_time[i] <
            burst_time[smallest] && burst_time[i] > 0)
            {
                smallest = i;
            }
        }
        burst_time[smallest]--;
        if (burst_time[smallest] == 0)
        {
            count++;
            end = time + 1;
            wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
            turnaround_time = turnaround_time + end - arrival_time[smallest];
        }
    }
    average_waiting_time = wait_time / limit;
    average_turnaround_time = turnaround_time / limit;
    cout << "\n\nAverage Waiting Time:\t" << average_waiting_time << endl;
    cout << "Average Turnaround Time:\t" << average_turnaround_time << endl;
    return 0;
}
