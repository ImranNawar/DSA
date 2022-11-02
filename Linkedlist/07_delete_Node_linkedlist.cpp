//Deleting node from a linked list 

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

/*   DELETE FUNCTION    */
int Delete(struct Node *p, int index)
{
    struct Node *q=NULL;
    int x = -1, i;

    if(index < 1 || index > count(p))  //to check validity of index
        return -1;
    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);  //call function free, delete is key word in cpp
        return x;
    }
    else {
        for(i=0; i < index-1; i++)
        {
            q=p;
            p=p->next;
        }
        q->next = p->next;
        x=p->data;
        free(p);
        return x;
    }
}

int main()
{
    int A[]={3,5,7,10,15};
    create(A,5);
    cout<<"Deleted element is "<<Delete(first, 4);
    cout<<endl;

    Display(first);
    return 0;
}