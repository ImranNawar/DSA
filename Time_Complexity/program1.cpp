// Find the time compexity of the func1 function in the program show in program1.cpp as below

#include <iostream>
using namespace std;

void func1(int array[], int length)
{
    int sum=0;
    int product=0;

    for(int i=0; i<length; i++)
    {
        sum += array[i];
    }

    for(int i =0; i< length; i++)
    {
        product *= array[i];
    }
}

int main()
{
    int arr[] = {3,5,66};
    func1(arr,3);
    return 0;
}