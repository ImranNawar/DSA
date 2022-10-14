#include<iostream>
using namespace std;

struct Array {
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

int Delete(struct Array *arr,int index) //As it is going to modify array it should be call by address type
{
    int x = 0;
    if(index>=0 && index<= arr->length)//To check index is valid or not
    {
        x = arr->A[index];
        for(int i=index; i<arr->length-1; i++)
           arr->A[i] = arr->A[i+1];  //This will shift all the elements
        arr -> length--;   //After shifting length of an array should be decremented
        return x;     //value x whatever the value is deleted
    }
    return 0;  //if element is not found return 0
}

int main()
{
    struct Array arr={{8,3,7,12,15,6,9,10},10,8};

    cout<<"\n "<<Delete(&arr,4);
    display(arr);
}