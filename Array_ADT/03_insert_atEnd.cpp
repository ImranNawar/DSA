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

//adding  NEW ELEMENT AT END
void append(struct Array *arr, int x) //As it is going to modify array it should be call by address type
{
    if(arr->length < arr->size)   //to check free space 
        arr->A[arr->length++]=x;
}

void insert(struct Array *arr, int index, int x)//As it is going to modify array it should be call by address type
{                                                //x is element to be insert
    int i;
    if(index>=0 && index <= arr->length)
    {
        for(i=arr->length; i>index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }
}

int main()
{
    struct Array arr={{1,2,3,4,5},10,5};  

    insert(&arr,5,10 ); //pass array as parameter by address, index,element
 //   append(&arr,10); //passing address of arr and value we want to insert
    display(arr);   //call the function by passing arr

}