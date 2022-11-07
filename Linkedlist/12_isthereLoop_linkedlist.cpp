// To check whether the linked list is linear or having loop
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

int isLoop (struct Node *f)
{
    struct Node *p, *q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p&&q && p!=q);

    if(p==q)
        return 1;
    else 
        return 0;
}

int main()
{
    struct Node *t1, *t2;   //temporary nodes
    int A[]={3,5,7,10,15};
    create(A,5);

    t1 = first -> next -> next;
    t2 = first -> next -> next -> next -> next;  //t2 pointing on last node
    t2 -> next =t1;        // from 15 it is pointing on 7 (loop)

    cout<<isLoop(first);
    return 0;
}