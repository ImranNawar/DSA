// C++ class for the linked list functions

#include<iostream>
using namespace std;

class Node 
{
    public:
        int data;
        Node *next;
};

class LinkedList
{
    private:
        Node *first;
    public:
        LinkedList()  //constructor
        {
            first = NULL;
        }
        LinkedList(int A[], int n);
        ~LinkedList();

        void Display();
        int count();  // LENGTH
        void Insert(int index, int x);
        int Delete(int index);
        int isSorted();
        int sum();
        int Max();
        int Min();
        void Merge();
       
          

};

//Definition of  functions using scope resolution operator
LinkedList:: LinkedList(int A[], int n)
{
    int i;
    Node *t, *last;
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

LinkedList:: ~LinkedList()
{
    Node *p =first;
    while(first)
    {
        first =first -> next;
        delete p;
        p = first;
    }
}
void LinkedList:: Display()
{
    Node *p =first;

    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int LinkedList:: count() // LENGTH
{
    Node *p = first;
    int len=0;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void LinkedList:: Insert(int index, int x)
{
    Node *t, *p=first;
    int i;

    if(index<0 || index > count())
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
int LinkedList:: Delete(int index)
{
    Node *p, *q=NULL;
    int x = -1, i;

    if(index < 1 || index > count())  //to check validity of index
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
        free(p);  // free or delete
        return x;
    }
}
int LinkedList:: isSorted()
{
    Node *p = first;
    int x = -65536;
    while(p != NULL)
    {
        if(p->data < x)
            return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}
int LinkedList:: sum()
{
    Node *p = first;
    int s=0;
    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}
int LinkedList:: Max()
{
    Node *p = first;
    int max=INT32_MIN;

    while(p)
    {
        if(p->data > max)
            max = p->data;
        p=p->next;
    }
    return max;
}
int LinkedList:: Min()
{
    Node *p = first;
    int min=INT32_MAX;

    while(p)
    {
        if(p->data < min)
            min = p->data;
        p=p->next;
    }
    return min;
}

void Merge()
{
    Node *p ;
    Node *q ;
    Node *last;
    Node *third;
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
    int A[] = {1,2,3,4,5};
    LinkedList l(A,5);

    //cout<<l.Delete(1)<<endl;

    // l.Insert(0,10);

    

    // cout<<l.count();

     cout<<l.Delete(2);

    // cout<<l.Max();

    // cout<<l.Min();

    // cout<<l.sum();

    // cout<<l.isSorted();

    l.Display();
    
    return 0;
}