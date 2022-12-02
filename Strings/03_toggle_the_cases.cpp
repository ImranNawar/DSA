// Toggle the cases. Change lower case to upper and upper case to lower case alphabets
// and the other characters will be remain untouched

#include <iostream>
using namespace std;

int main()
{
    char A[] = "WelCome";
    int i;

    for(i=0; A[i] != '\0'; i++)
    {
        if(A[i]>=65 && A[i]<=90)
        {
            A[i] += 32;
        }
        else if(A[i] >= 'a' && A[i] <= 122)
        {
            A[i] -= 32;
        }
    }
    cout<<A;
}