#include<iostream>
using namespace std;
int main()
{
    int n, bt[20], wt[20], tat[20], avwt=0, avtat=0;
    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"\nEnter the burst time for each process:\n";
    for(int i=0;i<n;i++)
    {
        cout<<"Process "<<i+1<<": ";
        cin>>bt[i];
    }
    wt[0]=0;   
    for(int i=1;i<n;i++)
    {
        wt[i]=0;
        for(int j=0;j<i;j++)
            wt[i]+=bt[j];
    }
    cout<<"\nProcess\tBurst Time\tWaiting Time\tTurnaround Time";
    for(int i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        cout<<"\n"<<i+1<<"\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
    }
    avwt/=n;
    avtat/=n;
    cout<<"\n\nAverage Waiting Time: "<<avwt;
    cout<<"\nAverage Turnaround Time: "<<avtat;
    return 0;
}
