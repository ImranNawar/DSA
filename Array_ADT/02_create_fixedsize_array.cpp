#include<iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    cout<<"\n Elements are \n";
    for(int i=0; i<arr.length; i++)
        cout<<arr.A[i]<<" ";
}

int main()
{
    struct Array arr={{1,2,3,4,5},10,5};  

    display(arr);   //call the function by passing arr
}