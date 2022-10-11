#include<iostream>
using namespace std;

int x = 0; //local variable , both local and static variable gave same result
int fun(int n)
{
  //  static int x = 0; //static variable
    if(n>0)
    {
        x++;
        return fun(n-1)+x;
    }
    return 0;
}

int main()
{
    int a;
    a = fun(5);
    cout<<a<<endl;

    return 0;
}