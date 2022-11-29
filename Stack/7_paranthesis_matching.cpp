// Parathesis Matching : To check whether the expression is parathesized or not
//ERROR
#include <iostream>
using namespace std;


struct Node 
{
    char data;
    struct Node *next;
}*top=NULL;

void push(char x)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    // t = new Node();

    if(t==NULL)
       cout<<"Stack is full \n";
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}
char pop()
{
    struct Node *t;
    char x = -1;

    if(top == NULL)
        cout<<"Stack is empty \n";
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void Display ()
{
    struct Node *p;
    p = top;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";
}

int isBalanced(char *exp)
{
    int i;

    for(i=0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i] == ')')
        {
            if(top==NULL)
              return 0;
            pop();
        }
    }
    if(top == NULL)  //to check if stack is empty
        return 1;
    else
        return 0;
}


int main()
{
    char *exp="((a+b)*(c-d))";

    printf("%d ", isBalanced(exp));
    // cout<<isBalanced(exp);

    return 0;
}