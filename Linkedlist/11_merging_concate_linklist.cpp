// concatination and merging of two linked lists
#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;  
}*first=NULL, *second=NULL, *third=NULL;  

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
 /* This will create second linked list*/
void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;

    for(i=1; i<n; i++)  
    {
        t = new Node;
        t->data=A[i];
        t->next= NULL;
        last->next=t;
        last = t;  
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
/*CONCATINATION FUNCTION*/
void Concate(struct Node *p, struct Node *q)
{
    third = p;
    while(p->next != NULL)
        p=p->next;
    p->next=q;
}

/*  MERGING TWO LINKED LISTS */
void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if(p->data < q->data)   //for first node
    {
        third = last =p;
        p=p->next;
        third -> next = NULL;
    }
    else{
        third = last =q;
        q=q->next;
        third -> next = NULL;
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
            last -> next =p;
            last = p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last -> next =q;
            last = q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)last -> next=p;
    if(q)last -> next=q;
}

int main()
{
    int A[]={4,6,8,10,12};
    int B[]={1,5,7,9,11};
    create(A,5);
    create2(B,5);

    // cout<<"First \n";
    // Display(first);
    // cout<<endl;
   
    // cout<<"Second \n";
    // Display(second);
    
    // Concate(first, second);
    // cout<<"Concatinated \n";
    // Display(third);
    
    Merge(first,second);
    Display(third);
    

    return 0;
}