//Finding maximum element in a linked list
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

/*             MAXIMUM         */ 
int Max(struct Node *p)
{
    int max=INT32_MIN;

    while(p)
    {
        if(p->data > max)
            max = p->data;
        p=p->next;
    }
    return max;
}
/*        RECURSIVE FUNCTION FOR MAXIMUM   */
int RMax(struct Node *p)
{
    int x=0;
    if(p==0)
       return INT32_MIN;
    x=RMax(p->next);
    if(x > p->data)
       return x;
    else
       return p->data;
    
}


/*             MiniMUM         */ 
int Min(struct Node *p)
{
    int min=INT32_MAX;

    while(p)
    {
        if(p->data < min)
            min = p->data;
        p=p->next;
    }
    return min;
}

int main()
{
    int A[]={3,5,7,10,15};
    create(A,5);

    cout<<"Maximum is "<<Max(first);
    cout<<"Maximum is "<<RMax(first);
    cout<<"Manimum is "<<Min(first);
    return 0;
}