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
    cout<<"\n Elements of array are \n";
    for(int i = 0; i< arr.length; i++)
        cout<<arr.A[i]<<" ";
}

// ITERATIVE PROCEDURE
int binarySearch(struct Array arr, int key )
{
    int l,  h, mid;
    l=0; 
    h=arr.length;


    while(l<=h)
    {
        mid=(l+h)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            h=mid-1;
        else
            l= mid+1;
    }
    return -1; //  if it return -1 means unsuccesful search
}

// RECURSIVE PROCEDURE
int rbinarySearch(int a[], int l, int h, int key)
{
    int  mid;

    if(l<=h)
    {
        mid=(l+h)/2;
        if(key == a[mid])
            return mid;
        else if(key<a[mid])
            return rbinarySearch(a, l, mid-1, key);
        else
            return rbinarySearch(a, mid+1, h, key);
    }
    return -1;
}

int main(){
    struct Array arr = {{2,3,4,5,6},10,5};

    cout<<" \n "<<binarySearch(arr,5); // --for iterative

    cout<<"\n "<<rbinarySearch(arr.A,0, arr.length, 6); // for recursive
    display(arr);
    return 0;
}