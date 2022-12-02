// Counting the number of vowels and consonents in a string.

#include <iostream>
using namespace std;

int main()
{
    char S[] = "How are you";
    int i, vcount=0, ccount=0;

    for(i=0; S[i] != '\0'; i++)
    {
        if(S[i]=='a'||S[i]=='e'||S[i]=='i'||S[i]=='o'||S[i]=='u'
        ||S[i]=='A'||S[i]=='E'||S[i]=='I'||S[i]=='E'||S[i]=='U')
            vcount++;
        else if(S[i]>=65 && S[i]<=90 || S[i] >= 97 && S[i] <=122)
            ccount++;
    }
    cout<<vcount<<"\n"<<ccount;
    return 0;
}