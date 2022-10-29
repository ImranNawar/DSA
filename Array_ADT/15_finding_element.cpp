//Finding single missing element in sorted array - (first n natural numbers)
//One Approach

//Finding missing element in sorted array of first natural numbers
#include<iostream>
using namespace std;

int main()
{
    int A[11] = {1,2,3,4,5,7,8,9,10,11,12};
    int sum=0, s, missing;
    int n =12; //largest number
    for(int i=0; i<n; i++)
    {
        sum= sum+A[i];
    }

    s= n*(n+1)/2;

    missing = s-sum;
    cout<<"Missing number "<<missing;

    return 0;
}