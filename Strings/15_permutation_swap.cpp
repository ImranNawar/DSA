// 2nd method for generating permutations of string  //issue
// This method will use swapping

#include <iostream>
using namespace std;

void perm(char S[], int l, int h)
{
    int i;
    if(l==h)
    {
        cout<<S<<" ";
    }
    else
    {
        for(i=l; i<=h; i++)
        {
            swap(S[l], S[i]);
            perm(S, l+1, h);
            swap(S[l], S[i]);
        }
    }
}

int main()
{
    char S[] = "ABC";

    perm(S, 0, 3);
}