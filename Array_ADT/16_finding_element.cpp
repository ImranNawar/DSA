// Finding single missing element in sorted array - (if the elements
//are not first n natural numbers)
//2nd Approach

#include<iostream>
using namespace std;

int main()
{
    int A[11] = {6,7,8,9,10,11,13,14,15,16,17};

    int difference,l, h,n;
    l=6; h=17; n=12;
    difference=l-0;
    for(int i =0; i<n; i++)
    {
        if(A[i]-i  !=  difference)
           {
            cout<<"Missing element is "<<i+difference;
            break;
           }
    }
}

//With the help of indices we can find out the missing element