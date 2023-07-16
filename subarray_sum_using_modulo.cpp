#include <bits/stdc++.h>
using namespace std;

int max_subarray(int arr[],int n, int m)
{
    int prefix_sum =0, max_sum= 0;
    for(int i = 0; i<n; i++)
    {
        prefix_sum= (prefix_sum + arr[i])%m;
        max_sum = max(max_sum, prefix_sum);
        int j=upper_bound(arr, arr+i, arr[i])-arr;
        if(j>0)
        {
            max_sum = max(max_sum,(prefix_sum - arr[j-1]+m)%m);
        }
    }
    return max_sum;
}
int main()
{
  int arr[] ={1,-2,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int m ;
  cout<<"Enter the value m :- ";
  cin>>m;
  int result = max_subarray(arr, n, m);
  cout<<"The maximum subarr sum "<<m<<" is "<<result<<endl;
  return 0;
}
