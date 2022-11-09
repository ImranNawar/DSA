// INSERTION FUNCTION AND LENGTH FUNCTION IN A CIRCULAR LINKED LIST
#include<iostream>
using namespace std;

struct Node 
{
    int data;
    struct Node *next;
}*Head;

/*          CREATE  FUNCTION        */
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head = new Node;
    Head->data = A[0]; 
    Head->next = NULL;
    last = Head;

    for(i=1; i<n; i++)  
    {
        t = new Node;
        t->data=A[i];
        t->next= NULL;
        last->next=t;
        last = t; 
    }
}

/*      DISPLAY FUNCTION  */
void Display(struct Node *h)
{
    do
    {
        cout<<h->data<<"  ";
        h=h->next;
    } while (h != Head);
}

/*    LENGTH FUNCTION   (COUNT)*/
int Length(struct Node *p)
{
    int len = 0;
    do
    {
       len++;
       p = p ->next;
    }while(p!= Head);
    return len;    
}


/*    INSERT FUNCTION    */ //not working
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if(index <0 || index > Length(p))  // checking if index is valid or not
        return;

    if(index == 0)//checking if index is zero
    {
        t = new Node;
        t->data=x;
        if(Head == NULL)
        {
            Head = t;
            Head -> next = Head;
        }
        else{
            while(p -> next != Head)p=p->next;
            p->next = t;
            t->next = Head;
            Head = t;
        }
    }

    else   //if index is not zero
    {
        for(i=0; i<index-1; i++)p=p->next;// move p and point it on the index where we want to insert
        t = new Node;
        t ->data= x;
        t -> next = p-> next;
        p-> next = t;
    }
}

int main()
{
    int A[] = {2,3,4,5,6};
    create(A,5);

    Insert(Head,2,10);
    Display(Head);

    return 0;
}