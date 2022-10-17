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

////////  GET FUNCTON  ///////
int get(struct Array arr, int index) //It should be called by value because it is not going to modify array
{
    if(index >= 0 && index < arr.length) // to check whether given index is valid or not
        return arr.A[index];
    return -1;    //otherwise
}

////////  SET FUNCTION  ////////
void set(struct Array *arr, int index, int x) //It should be call by addres because it is going to modify array
{
    if(index >=0 && index < arr->length)
        arr->A[index] = x;
}

/////////  MAXIMUM FUNTION  //////////
int Max(struct Array arr)
{
    int max = arr.A[0];
    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

///// MINIMUM FUNTION  ///////////
int Min(struct Array arr)
{
    int min = arr.A[0];
    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}
 /////// SUM FUNCTION  ////////
int sum(struct Array arr)
{
    int s =0;
    for(int i =0; i<arr.length; i++)
        s+=arr.A[i];

    return s;
}

//////// FLOAT FUNCTION ////////
float avg(struct Array arr)
{
    return (float)sum(arr)/arr.length;  //type casted as float - - i call the sum functon by passing array
}
int main()
{
    struct Array arr={{2,3,14,5,6},10,5};

//    cout<<"value at the given index is : "<<get(arr,2);
//    set(&arr, 0, 15); //change index  0 value with 15
//    cout<<Max(arr);
//    cout<<Min(arr);
//    cout<<sum(arr);
    cout<<avg(arr);
    display(arr);
    return 0;
} 