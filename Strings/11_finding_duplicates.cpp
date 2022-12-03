// Finding duplicates in a string. There are three methods.
//1)Compare with other letters 2) using hash table 3) Using Bits
// The below program is using hashtable


//Error in printing
#include<iostream>
using namespace std;

int main ()
{
    char A[] = "finding";
    int H[26], i;

    for(i=0; A[i] != '\0'; i++)
    {
        H[A[i]-97] += 1;
    }
    for(i=0; i<26; i++)
    {
        if(H[i] > 1)
        {
            printf("%c", i+97);
            printf("%d ", H[i]);
           //cout<<i+97;
           //cout<<H[i];
        }
    }
}