//Finding missing element in unsorted Array
// METHOD 2: USING HASH TABLE

#include<iostream>
using namespace std;

int main()
{
    int A[10]={3,7,4,9,12,6,1,11,2,10};
    int *H;
    H = new int[12];  //Array in heap by default initialize with 0
    
    int l=1,h=12, n=10;

    for(int i=0; i<n; i++)
    {
        H[A[i]]++;
    }
    for(int i=l; i<=h; i++)
    {
        if(H[i] == 0)
           cout<<i<<endl;
    }
}