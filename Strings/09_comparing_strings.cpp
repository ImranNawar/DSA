// Comparing two string whether it is same or not. In this program it will not ignore upper and lower cases

#include<iostream>
using namespace std;

int main()
{
    char A[] = "Painter";
    char B[] = "Painting";
    int i, j;

    for(i=0, j=0; A[i] != '\0' &&
    B[i] != '\0'; i++, j++)
    {
        if(A[i] != B[i])
           break;
    }
    if(A[i] == B[i])
        cout<<"Equal"; 
    else if(A[i] < B[j])
        cout<<"Smaller";
    else
        cout<<"Greater";
    }