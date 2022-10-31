// functions for counting number of nodes in linkedlist and
// the sum of data in a linked list
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
/*         COUNT FUNCTION          */
int count (struct Node *p)
{
    int l=0;
    while(p)
    {
        l++;
        p = p->next;
    }
    return l;
}
/*         RECURSIVE COUNT FUNCTION      */
int Rcount(struct Node *p)
{
    if(p!=NULL)
        return Rcount(p->next)+1;
    else  
        return 0;
}

/*           SUM                      */
int sum(struct Node *p)
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}

/*       RECURNSIVE SUM FUNCTION    */
int Rsum(struct Node *p)
{
    if(p==NULL)
       return 0;
    else
       return Rsum(p->next)+p->data;
}

int main()
{
    int A[]={3,5,7,10,15,6,23,40};
    create(A,8);
    // cout<<"Length is "<<Rcount(first);

    // cout<<"Sum is "<<sum(first);
    cout<<"Sum is "<<Rsum(first);

    return 0;
}