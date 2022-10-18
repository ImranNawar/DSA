// WRITE THE ARRAY CLASS AND CONVERT IT INTO TEMPLATE CLASS

#include<iostream>
using namespace std;


template<class T>    // for creating generic array --float, int ... 

class Array       // A class in cpp should have data members and data functions
{
    private:
       T *A;
       int size;
       int length;
    public:
       Array()        //default constructor
       {
        size = 10;
        A = new T[10];
        length=0;
       }
       Array(int sz) //parametarized constructor
       {
        size = sz;
        length=0;
        A=new T[size];
       }
       ~Array()     // destructor release resourses here we create array in heap
       {
        delete []A;
       }

       void Display(); 
       void Insert(int index, T x);
       T Delete (int index);

};

//the affect of template has finished at the end of class
//when we are implementing function outside the class using scope resolution operator
// then for each funtion we should right template 

// now implement the functions
template<class T>
void Array<T>:: Display()
{
    for(int i = 0;i<length; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

template<class T>
void Array<T>:: Insert(int index, T x)
{
    if(index >= 0 && index <= length)
    {
        for(int i=length-1; i>=index; i--)
           A[i+1] = A[i];
        A[index] = x;
        length++;
    }
}

template<class T>
T Array<T>::Delete(int index)
{
    T x=0;
    if(index>=0 && index<length)
    {
        x = A[index];
        for(int i=index; i<length-1; i++)
            A[i] = A[i+1];
        length--;
    }
    return x;
}

int main()
{
    Array<float> arr(10);
    arr.Insert(0,5.2);
    arr.Insert(1,6.5);
    arr.Insert(2,9.5);
    arr.Display();

    cout<<arr.Delete(0)<<endl;
    arr.Display();
    return 0;
}

// by use of template now you can take any data type and change the array