//Finding multiple missing elements in an Array
#include<iostream>
using namespace std;
int main()
{
    int A[11]={6,7,8,9,11,12,15,16,17,18,19};
    int l=6, h=19, n=11;
    int difference;
    difference=l-0;
    for(int i=0; i<n; i++)
    {
        if(A[i]-i  !=  difference)
        {
            while(difference < A[i]-i)
            {
               cout<<"Missing elements "<<i+difference<<endl;
               difference++;
            }
        }
    }
}