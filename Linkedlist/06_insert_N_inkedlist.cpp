//Insert a new Node in a linked list
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
/*          INSERT FUNCTION          */
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if(index<0 || index > count(p))
        return;
    t= new Node;
    t->data = x;

    if(index == 0)//insert as first node
    {
        t->next = first;
        first = t;
    }
    else   //at another position
    {
        for(i=0; i<index-1; i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}

/*     INSERT AT LAST -- it will take constant time  */
//just inserting one node at end of  a linked list
void InsertLast(int x){
    struct Node *last;
    Node *t = new Node;
    t->data = x;
    t->next =NULL;
    if(first == NULL)
    {
        first = last =t;
    }
    else{
        last -> next=t;
        last =t;
    }
}

/*    INSERT NEW NODE IN SORTED LINKED LIST  */
void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q=NULL;

    t=new Node;
    t->data=x;
    t->next=NULL;

    if(first == NULL)
        first = t;
    else{
        while (p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}

int main()
{
    // int A[]={3,5,7,10,15};
    // create(A,5);
    

    // using the insert function, try to create entire linked list;

    // Insert(first,0,10);
    // Insert(first,1,20);
    // Insert(first,2,30);
    // Insert(first, 0, 5);

    // InsertLast(4);
    // InsertLast(78);

    int A[]={3,5,7,10,15};
    create(A,5);
    SortedInsert(first, 9);

    Display(first);
    cout<<endl;
    return 0;
}