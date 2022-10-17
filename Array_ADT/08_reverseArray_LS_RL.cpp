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

void swap(int *x, int *y)   // Swapping two elements
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

//////    REVERSING ARRAY BY USING AUXILLARY ARRAY B   /////////////

void Reverse(struct Array *arr)
{
    int *B;            // Array B should of size equal to array A
    int i,j;
    
    B = new int[arr->length];  //create array B from heap by new operator length must be equal to arra y A
    for(i=arr->length-1,j=0;i>=0;i--,j++) // reverse copying all the elements from array A to arraY B
    B[j]=arr->A[i];

    for(i=0;i<arr->length;i++)
    arr->A[i]=B[i];
}

///// Reversing the array by exchanging first and last and corresponding elements
void Reverse2(struct Array *arr)
{
    int i, j;
    for(i= 0,j=arr->length-1; i<j; i++,j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

//LEFT SHIFT
//RIGHT SHIFT
//LEFT ROTATE
//RIGHT ROTATE

int main()
{
    struct Array arr = {{2,3,4,5,6},10,5};

 //   Reverse(&arr);
 Reverse2(&arr);
    display(arr);
    return 0;
}