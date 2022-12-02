// changing case of a string
// from upper to lower case add 32, and from lower to upper case subtract 32

#include<iostream>
using namespace std;

int main()
{
    char A[] = "WELCOME";
    int i;

    for(i=0; A[i] != '\0'; i++)
    {
        A[i] = A[i] + 32;
    } 
    cout<<A;
}