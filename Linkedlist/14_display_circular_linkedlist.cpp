//Crreate function for circular linked list, Display function for circular linked list -- Both iterative and recursive
#include<iostream>
using namespace std;

struct Node 
{
    int data;
    struct Node *next;  //self referential pointer
}*Head;   //global pointer


/*          CREATE  FUNCTION        */
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head = new Node;
    Head->data = A[0];  //Head pointing on itself that's how we make it circular
    Head->next = NULL;
    last = Head;

    for(i=1; i<n; i++)  //already 0th element is created
    {
        t = new Node;
        t->data=A[i];
        t->next= NULL;
        last->next=t;
        last = t;  //last should move on new node 't'
    }
}

/*      DISPLAY FUNCTION  ITERATIVE PROCEDURE  */
void Display(struct Node *h)
{
    do
    {
        cout<<h->data<<"  ";
        h=h->next;
    } while (h != Head);
}

/*      DISPLAY FUNCTION  RECURSIVE PROCEDURE  */
void RDisplay(struct Node *h)
{
    static int flag=0;   // static is because of to use only single copy
    if(h!=Head || flag == 0)
    {
        flag =1;
        cout<<h->data<<" ";
        RDisplay(h->next);
    }
    flag=0;
}
int main()
{
    int A[] = {2,3,4,5,6};
    create(A,5);

    // Display(Head);
    RDisplay(Head);
    return 0;
}