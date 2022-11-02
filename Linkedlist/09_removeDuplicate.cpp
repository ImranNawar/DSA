//Remove duplicated nodes in a sorted linked list
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

/*   REMOVE DUPLICATED   FUNCTION    */
void RemoveDuplicate(struct Node *p)
{
    struct Node *q =p -> next;  // p as tail pointer 

    while (q!=NULL)
    {
        if(p->data != q->data)
        {
            p=q;
            q=p->next;
        }
        else{
            p->next = q->next;
            free(q);
            q=p->next;
        }
    }
}

int main()
{
    int A[]={3,5,5,5,7,10,15};
    create(A,7);

    RemoveDuplicate(first);

    Display(first);
    return 0;
}