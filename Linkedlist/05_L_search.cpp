// linear search for linked list  --- move to front operation 
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

/*       ITERATIVE VERSION OF LINEAR SEARCH       */
struct Node * L_search(struct Node *p, int key) //it should return structure type node
{
    while(p!=NULL)
    {
        if(key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

/*       MOVE TO FRONT LINEAR SEARCH       */
struct Node * M_L_search(struct Node *p, int key) //it should return structure type node
{
    struct Node *q=NULL;
    while(p!=NULL)
    {
        if(key == p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

/*      RECURSIVE VERSION OF LINEAR SEARCH        */
struct Node * R_search(struct Node *p, int key)
{
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return R_search(p->next,key);
}

int main()
{
    struct Node *temp;   //temporary node
    int A[]={3,5,7,10,15};
    create(A,5);

    // temp= R_search(first, 10);
    // if(temp)
    //     cout<<"Key is found "<<temp->data;
    // else 
    //     cout<<"Key not found ";

    temp = M_L_search(first,15);
    if(temp)
        cout<<"Key is found "<<temp->data<<endl;
    else 
        cout<<"Key not found \n";

    Display(first);
    return 0;
}