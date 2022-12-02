// Reversing string.  There are more than one methods for reversing


//Some problem with printing
#include <iostream>
using namespace std;

int main()
{
    char A[] = "Python";
    char B[7];
    int i,j;

    for(i=0; A[i] != '\0'; i++)
    {

    }
    i=i-1;       //IN the below loop error
    for(j=0; j>=0; i--, j++)
    {
        B[j] = A[i];
    }
    B[j]= '\0';
    cout<<B;


}