#include<iostream>
using namespace std;

int fun(int n)
{
    if(n>100)
        return n-10;
    else
        return fun(fun(n+11));
}

int main()
{
    int r;
    r = fun(95);  //for any value less than or equal to 100 it will return 91
    cout<<r<<"\n ";
    return 0;
}