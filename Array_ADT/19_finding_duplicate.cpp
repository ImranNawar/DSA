//Finding duplicates in sorted arry

#include<iostream>
using namespace std;

int main()
{
    int A[10]={3,6,8,8,10,12,15,15,15,20};
    int lastDuplicate = 0;
    int n=10;
    for(int i=0; i<n; i++)
    {
        if(A[i] == A[i+1] && A[i] != lastDuplicate)
        {
            cout<<A[i]<<" is duplicate in array "<<endl;
            lastDuplicate =A[i];
        }
    }
}