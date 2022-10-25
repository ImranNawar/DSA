// Some problem in code

#include<iostream>
using namespace std;

int main()
{
    int A[10]={3,6,8,8,10,12,15,15,15,20};
    int n=10, l=3, h=20;  // h means maximum element
    int *H;
    H = new int[20];  // Array in heap by default initialize with 0
                      //size is 20 becouse largest element is 20.
    
    for(int i=0; i<n; i++)
    {
        H[A[i]]++;
    }
    for(int i=0; i<=h; i++)
    {
        if(H[i] > 1)
           cout<<i<<" "<<H[i]<<endl;
    }
}