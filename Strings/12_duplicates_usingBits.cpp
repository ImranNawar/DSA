//Finding duplicates in a string using Bitwise method


//Error
#include <iostream>
using namespace std;

int main()
{
    char A[]  ="finding";
    long int H=0, x=0, i;

    for(i=0; A[i] != '\0'; i++)
    {
        x=1;
        x=x<<A[i]-97;
        if(x & H > 0)
        {
            cout<<A[i] << "is Duplicate";
        }
        else
           H= x | H;
    }
}