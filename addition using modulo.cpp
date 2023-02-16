#include<iostream>
using namespace std;

int main()
{
    int x,y,m;
    int dividend, divisor, quotient, remainder;

    cout<<"Enter the values of x:- ";
    cin>>x;

    cout<<"Enter the value of y:- ";
    cin>>y;

    cout<<"Enter the value of m:- ";
    cin>>m;

    dividend=x+y;

    divisor=m;
    
    quotient = dividend/m;
    remainder = dividend - (divisor*quotient);

    cout<<"The result:- "<<remainder;

}
