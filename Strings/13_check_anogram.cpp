// Checking if two strings are anogram.
// Anogram are two set of strings which are formed using same set of alphabets.

//Logical error
#include<iostream>
using namespace std;

int main()
{
    char A[] = "decimal";
    char B[] = "medical";
    int i, H[26] ={0};

    for(i=0; H[i] != '\0'; i++)
    {
        H[A[i] - 97] += 1;
    }
    for(i=0; B[i] != '\0'; i++)
    {
        H[A[i] -97]-=1;
        if(H[A[i] - 97] < 0)
        {
            cout<<"Not Anogram";
            break;
        }
        if(B[i] == '\0')
           cout<<"Its Anogram";
    }
}