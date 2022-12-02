// Counting number of words in string.
//Spaces will help us in finding the words, spaces+1

#include<iostream>
using namespace std;

int main()
{
    char A[] = "How are you";
    int i, word=1;

    for(i=0; A[i] != '\0'; i++)
    {
        if(A[i]==' ' && A[i-1]!=' ')  //the second condition take care of white spaces (more than 1 space)
        {
            word++;
        }
    }
    cout<<word;
}