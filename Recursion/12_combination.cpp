#include<iostream>
using namespace std;

int facto(int n)   /// FACTORIAL FUNCTION  --recursive
{
    if(n==0)
    {
        return 1;
    }
    else
      return facto(n-1)*n;
}

int nCr(int n, int r)///COMBINATION FUNCTION   --this is not recursive
{
    int num, den;

    num = facto(n);
    den=facto(r)*facto(n-r);

    return num/den;
}

// let's write recursive function to find nCr
int NCR(int n, int r){
    if(n==r || r==0)
       return 1;
    return NCR(n-1, r-1)+NCR(n-1,r);
}

int main()
{
    cout<<nCr(5,3)<<endl;
    cout<<NCR(5,3);

    return 0;
}