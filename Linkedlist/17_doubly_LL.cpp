// DOUBLY LINKED LIST: CREATE FUNCTION, DISPLAY FUNCTION , LENGTH FUNCTION, DELETE FUNCTION, REVERSE FUNCTION
#include<iostream>
using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

/**             CREATE FUNCTION          **/
void create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for(i=1; i<n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last -> next=t;
        last = t;
    }
}

/**       DISPLAY FUNCTION           **/
void Display(struct Node *p)
{
    while(p)
    {
        cout<<" "<<p->data;
        p=p->next;
    }
    cout<<"\n";
}

/**         LENGTH FUNCTION (COUNT)     **/
int Length(struct Node *p)
{
    int len=0;

    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

/**      INSERT FUNCTION     **/
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if(index < 0 || index > Length(p))   //checking index validation
        return;

    if(index==0)   //before first Node
    {
        t = new Node;
        t->data = x;
        t->prev=NULL;
        t->next = first;
        first->prev = t;
        first =t;
    }
    else   //insertion at any given position
    {
        for(i=0;i<index-1; i++)
            p=p->next;
        t=new Node;
        t->data = x;

        t->prev = p;
        t->next = p->next;
        if(p->next)p->next->prev=t;
        p->next=t;
    }
   
}

/**    DELETE FUNCTION    **/
int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x=-1, i;

    if(index < 1 || index > Length(p))  // checking index validation
         return -1;

    if(index == 1)  // deleting first node
    {
        first = first-> next;
        if(first)first->prev=NULL;

        x=p->data;
        free(p);
    }
    else   // deleting other nodes
    { 
        for (i = 0; i < index-1; i++)
            p = p->next;
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        free(p);
    }
    return x;
}

void Reverse(struct Node *p)
{
    struct Node *temp;  //temp pointer for swapping

    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next == NULL) //check if that is the last node
            first = p;
    }
}
int main()
{
    int A[] = {10,20,30,40,50};
    create(A,5);

    // cout<<"Length is : "<<Length(first)<<endl;
    // Display(first);

    // Insert(first,3,25);
    // Display(first);

    // Delete(first, 4);
    // Display(first);

    Reverse(first);
    Display(first);


    return 0;
}