#include <iostream>
using namespace std;

double e(int x, int n)  //RECURSIVE FUNCTION
{
    static double s;
    if(n == 0)
        return s;
    else
        s=1+(double)x/n*s;  ///TYPE CASTING
        return e(x, n-1);
}

double eT(int x, int n){  //ITERATIVE FUNCTION //USING FOR LOOP
    double s =1;
    int i;
    double num = 1;
    double den =1;

    for(i=1; i<=n; i++)
    {
        num*=x;
        den*=i;
        s+=num/den;
    }
    return s;
}

int main()
{

    cout<<eT(1, 10)<<endl;
    cout<<e(2, 10);
    return 0;
}