// Implementing Queue using  2 stacks
//if we have two stacks then we can use it as queue and perform inqueue and dequeue operations on it.


//THE PROGRAM IS NOT COMPLETE

#include<iostream>
using namespace std;


void enqueue (int x)
{
    push(&s1,x);
}

int dequeue()
{
    int x =-1;
    if(isEmpty(s2))
    {
        if(isEmpty(s1))
        {
            cout<<"Queue is empty";
            return x;
        }
        else
        {
            while(! isEmpty(s1))
              push(&s2, pop(&s1));
        }
    }
    return pop(&s2);
}