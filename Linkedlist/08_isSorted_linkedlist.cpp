// To check whether the linked list is sorted or not/*         COUNT FUNCTION          */
#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;   //self refrential pointer
}*first=NULL;   //global pointer--it can  be directly access or even it can be  passed as parameter

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

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<"  ";
        p=p->next;
    }
}

/*      IS SORTED   FUNCTION    */
int isSorted(struct Node *p)
{
    int x = -65536;
    while(p != NULL)
    {
        if(p->data < x)
            return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}

int main()
{
    int A[]={3,5,7,10,15};
    create(A,5);

    if(isSorted(first))
    {
        cout<<"sorted \n";
    }
    else 
    {
        cout<<"NOt sorted \n";
    }

    // Display(first);
    return 0;
}