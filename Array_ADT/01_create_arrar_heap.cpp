#include<iostream>
using namespace std;

struct Array
{
    int *A;
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
    int n,i;
    struct Array arr;  //struct type variable
    cout<<"Enter size of an array: ";
    cin>>arr.size;
    arr.length=0;
    arr.A = new int[arr.size];  //we create array in heap
    
    cout<<"Enter number of numbers ";
    cin>>n;

    cout<<"Enter all elements \n";
    for(i=0; i<n; i++)
        cin>>arr.A[i];
    arr.length=n;

    display(arr);   //call the function by passing arr

}