#include<iostream>
using namespace std;

int main()
{
    //Different ways of declaration and initialization
    int A[5];
    int B[5]={2,4,6,8,10};
    int C[5] = {2,4};
    int D[5] = {0};
    int E[] = {1,3,5,7,9,11};

    // Print the addresses of the array indeces -- to see that indeces are contiguous
    int X[5];
    for(int i =0; i<5; i++)
    {
        cout<<&X[i]<<endl;
    }
    return 0;
}