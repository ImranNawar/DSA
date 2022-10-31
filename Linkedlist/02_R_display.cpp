//Recursive display function

#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;   //self refrential pointer
}*first=NULL;   //global pointer--it can  be directly access or even it can be  passed as parameter

        /*  CREATE LINKED LIST  */
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1; i<n; i++)  //already 0th element is created
    {
        t = new Node;
        t->data=A[i];
        t->next= NULL;
        last->next=t;
        last = t;  //last should move on new node 't'
    }
}

/*        DISPLAY        */
void Display(struct Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<"  ";
        p=p->next;
    }
}

/*          RECURSIVE DISPLAY FUNCTION           */
void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        RDisplay(p->next);
    }
}

int main()
{
    int A[]={3,5,7,10,15};
    create(A,5);

    RDisplay(first);
    return 0;
}