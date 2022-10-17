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

struct Array* Merge(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    if(arr1->A[i]<arr2->A[j])
        arr3->A[k++]=arr1->A[i++];
    else
        arr3->A[k++]=arr2->A[j++];
    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}
//////////  UNION FOR SORTED ARRAYS //////
// union for sorted array is same as merging
struct Array* Union(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
             arr3->A[k++]=arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
             arr3->A[k++]=arr2->A[j++];
        else
        {
            arr3-> A[k++] = arr1 ->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j]; 
    arr3->length =k;
    arr3->size = 10;

    return arr3;
}

////////// INTERSECTION OF Two sorted sets ///////
struct Array* Intersection(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else if(arr1 ->A[i] == arr2 -> A[j])
        {
            arr3 -> A[k++] = arr1 -> A[i++];
            j++;
        }
    }
     
    arr3->length =k;
    arr3->size = 10;

    return arr3;
}

///////  DIFFERENCE OF TWO SORTED ARRAYS ////
struct Array* Difference(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
             arr3->A[k++]=arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    
    arr3->length =k;
    arr3->size = 10;

    return arr3;
}

//SET MEMBERSHIP FUNCTON //// ---- it is same as search
int membership(struct Array arr,int key)//we are not passing by address because we are not modifying array
{
    for(int i =0; i<arr.length; i++)  //in call by value we use dot . and in call by address we use arrow ->
    {
        if(key == arr.A[i])
            return i;
    }
    return -1;
}

int main()
{
    struct Array arr1={{2,6,10,15,25},10,5};
    struct Array arr2={{3,6,7,15,20},10,5};
    struct Array *arr3; 

  //  arr3 = Merge(&arr1, &arr2);
  //  arr3 = Union(&arr1, &arr2);
  //  arr3 = Intersection(&arr1, &arr2);
  //  arr3 = Difference(&arr1, &arr2);
    cout<<"\n "<<membership(arr1,6);
    display(*arr3);

    return 0;
}