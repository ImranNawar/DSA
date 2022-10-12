#include<iostream>
using namespace std;

int main()
{
    int *p, *q;

    p = new int[5];
    p[0]={1};
    p[1]={3};
    p[2]={5};
    p[3]={7};
    p[4]={9};

    for(int i=0; i<5; i++)  //Print values of p array
    {
        cout<<p[i]<<" "<<endl;
    }

    q = new int[10];   //To increase my p array

    for(int i =0; i<5; i++)//Copy the element of p to q
    {
        q[i]=p[i];
    }
    delete p;
    p=q;
    q=NULL;
    for(int i=0; i<5; i++)
    {
        cout<<p[i]<<" ";
    }

}