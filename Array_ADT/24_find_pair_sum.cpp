//Find  a pair with sum k (a+b = k) in sorted array
#include<iostream>
using namespace std;

int main()
{
    int A[10]={1,3,4,5,6,8,9,10,12,14};
    int n=10;

    int i=0, j=n-1,k;
    cout<<"Enter key";
    cin>>k;

    while (i<j)
    {
        if(A[i]+A[j] == k)
        {
           printf("%d + %d = %d ", A[i], A[j],k);
            i++;
            j--;
        }
        else if (A[i] + A[j] < k)
            i++;
        else 
            j--;
    }

}