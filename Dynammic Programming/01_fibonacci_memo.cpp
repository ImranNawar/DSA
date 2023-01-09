// Fibonacci series using memoization

#include<iostream>
using namespace std;

int fib(int n)
{
    if(n <= 1)
       return n;
    
    // if(fib(n) != -1)
        // return fib(n);
    
    int res = fib(n-1) + fib(n-2);
    fib(n) = res;  //This statement "memoization"
    return res;
}

int main()
{
    int n, res[]={-1};
    cout<<"Enter an integer to find its fibonacci number ";
    cin>>n;

    return 0;
}