#include<iostream>
using namespace std;

int pow(int m, int n)
{
    if(n==0)
        return 1;
    return pow(m, n-1)*m;
}

//2nd version-------THIS WILL REDUCED NUMBER OF MULTIPLICATION
int pow1(int m, int n)
{
    if(n==0)
        return 1;
    if(n%2 == 0)   //EVEN
        return pow1(m*m, n/2);
    else             //ODD
       return m*pow1(m*m, (n-1)/2);
}

int main()
{
    int r = pow1(2,9);
    cout<<r;
    return 0;
}