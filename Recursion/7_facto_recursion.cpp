#include<iostream>
using namespace std;

int facto(int n)   ///RECURSIVE FUNCTION
{
    if(n==0)
    {
        return 1;
    }
    else
      return facto(n-1)*n;
}


 int Ifacto(int n)   ///ITERATIVE FUNCTION
 {
    int f=1;
    int i;
    for(i=1; i<=n; i++)
        f=f*i;
    return f;
 }

int main()
{
    int r;
    r= Ifacto(5);
    cout<<r;

    return 0;
}