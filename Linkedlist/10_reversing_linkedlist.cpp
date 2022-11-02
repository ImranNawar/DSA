// Reversing linked list
#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;   
}*first=NULL;

        /********  CREATE LINKED LIST ********/
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

/*         COUNT FUNCTION     (lenght of linked list)     */
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

/*      REVERSE FUNCTION  (REVERSING THE DATA)*/
void Reverse1(struct Node *p)
{
    int *A, i=0;
    struct Node *q=p;
    A = (int *)malloc(sizeof(int)*count(p));
    while(q != NULL)  //This loop will copy the elements from linked list to array
    {
        A[i] = q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q != NULL) //This loop will copy the elements from array to linked list
    {
        q->data = A[i];
        q=q->next;
        i--;
    }
}
/*     REVERSE FUNCTION (REVERSING LINKS)*/
void Reverse2(struct Node *p)
{
    struct Node *q=NULL, *r=NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    first = q;
}
/*    REVERSE FUNCTION (RECURSION)    */
void Reverse3(struct Node *q, struct Node *p)
{
    if(p)
    {
        Reverse3(p,p->next);
        p->next =q;
    }
    else
       first = q;
}
int main()
{
    int A[]={3,5,7,10,15};
    create(A,5);

    // Reverse1(first);
    // Reverse2(first);
    Reverse3(NULL,first);

    Display(first);
    return 0;
}