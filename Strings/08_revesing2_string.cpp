// Reversing string by 2nd method


//some problem with printing
#include <iostream>
using namespace std;

int main()
{
    char A[] = "Python";
    char t;
    int i, j;
    for(i=0; A[j] != '\0'; j++)
    {

    }
    j=j-1;  // Error in the below loop
    for(i=0; i<j; i++, j--)
    {
        t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
       cout<<A;  
}