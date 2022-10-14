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

// int linearsearch(struct Array arr,int key)//we are not passing by address because we are not modifying array
// {
//     for(int i =0; i<arr.length; i++)  //in call by value we use dot . and in call by address we use arrow ->
//     {
//         if(key == arr.A[i])
//             return i;
//     }
//     return -1;
// }
          /**********        MODIFY LINEAR SEARCH              *******************/
 

//  TRANSPORTATION METHOD

// int linearsearch(struct Array *arr,int key)//we are now passing array by address because we are now modifying array
// {
//     for(int i =0; i<arr->length; i++)  //in call by value we use dot . and in call by address we use arrow ->
//     {
//         if(key == arr->A[i])
//         {
//             swap(&arr->A[i], &arr->A[i-1]);//it will interchange element found at index i with element that is i-1
//             return i;
//         }
//     }
//     return -1;
// }

// MOVE TO FRONT / HEAD  METHOD

int linearsearch(struct Array *arr,int key)//we are now passing array by address because we are now modifying array
{
    for(int i =0; i<arr->length; i++)  //in call by value we use dot . and in call by address we use arrow ->
    {
        if(key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);//it will interchange element found at index i with element that is i-1
            return i;
        }
    }
    return -1;
}

int main()
{
    struct Array arr = {{2,3,4,5,6},10,5};

    cout<<"\n "<<linearsearch(&arr,5);
    display(arr);
    return 0;
}