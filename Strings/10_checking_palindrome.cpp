// for checking palindrome, there are two methods 
//1) take another array  and reverse copy the elements and then compare both the arrays
//2) without taking another array take two pointer each on a side and just compare the elements.

#include<iostream>
using namespace std;

int main()
{
    char A[] = "madam"; 
    int i, j;
    //revering 
    //comparing

    for(i=0; A[j] != '\0'; j++)
    {

    }
    j=j-1;  // Error in the below loop
    for(i=0; i<j; i++, j--)
    {
        if(A[i] == A[j])
        {
            cout<<"Palindrome";
            i++;
            j--;
        }
    }
}