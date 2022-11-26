 #include<iostream>
using namespace std;


struct Node{
    int data;
    struct Node* next;
};
struct Node* top = NULL;

                 /***********   TRAVERSAL   *********/
void linkedListTraversal(struct Node* ptr){
    while(ptr != NULL){
        cout<<"ELement : "<<ptr -> data; 
        ptr = ptr -> next;
    }
}
                 /***********   ISEMPTY FUNCTION   *********/
int isEmpty(struct Node* top){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
                 /***********   ISFULL FUNCTION   *********/
int isFull(struct Node* top){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
                 /***********   PUSH FUNCTION   *********/
struct Node* push(struct Node* top, int x){
    if(isFull(top)){
        cout<<"Stack overflow \n ";
    }
    else{
        struct Node* n = (struct Node*) malloc(sizeof(struct Node));
        n ->data = x;
        n -> next = top;
        top = n;
        return top;
    }
}
                 /***********   POP FUNCTION   *********/
int pop(struct Node* tp){
    if(isEmpty(tp)){
        cout<<"Stack underflow \n";
    }
    else{
        struct Node* n = tp;
        top = (tp) -> next;
        int x = n -> data;
        free(n);
        return x;
    }
}

/******   DISPLAY FUNCTION  ******/
void Display()
{
    struct Node *p;
    p=top;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<"\n";
}

int main(){
    //struct Node* top = NULL;

    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);
    Display();

    int element = pop(top);
    cout<<"Popped element is "<<element<<"\n";

    linkedListTraversal(top);


    return 0;
}