//Problem in code
//Finding duplicate element in unsorted array
#include<iostream>
using namespace std;

int main()
{
    int A[10]={8,3,6,4,6,5,6,8,2,7};
    int n=10,i,j;

    for(i=0; i<n-1; i++)
    {
        int count = 1;
        if(A[i] != -1)
        {
            for(j=i+1; i<n; j++)
            {
                if(A[i] == A[j])
                {
                    count ++;
                    A[j] = -1;
                }
            }
        }
        if (count > 1)
            cout << A[i] << count;
    }
}