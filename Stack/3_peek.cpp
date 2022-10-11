#include<iostream>
using namespace std;

struct stack{
    int size;
    int top;
    int * arr; // pointer to dynamically allocate memory
};
            /**********  ISEMPTY FUNCTION  ************/
int isEmpty(struct stack *ptr){
    if(ptr -> top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

          /**********  ISFULL FUNCTON  ************/
int isFull(struct stack *ptr){
    if(ptr -> top == ptr -> size-1){
        return 1;
    }
    else{
        return 0;
    }
}

           /***********  PUSH FUNCTION   ************/
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        cout<<"Stack overflow! cannot push "<<val<<" to the stack \n";
    }
    else{
        ptr -> top++;
        ptr -> arr[ptr -> top] =val;
    }
}

           /***********   POP FUNCTION   ************/
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        cout<<"Stack underflow! Cannot pop from the stack \n";
        return -1;
    }
    else{
        int val = ptr -> arr[ptr -> top];
        ptr -> top--;
        return val;
    }
}
              /*********   PEEK FUNCTIONS    ***********/
int peek(struct stack* sp, int i){
    int arrayInd = sp -> top -i +1;
    if(arrayInd < 0){
        cout<<"Invalid position for the stack \n";
        return -1;
    }
    else{
        return sp -> arr[arrayInd];
    }

}

int main(){
    //struct stack *sp; //pointer which point instance of stack
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));//actual instance of stack
    sp -> size = 10;
    sp -> top = -1;
    sp -> arr = (int *) malloc (sp -> size * sizeof(int));
    cout<<"Stack has been created successfully \n";

    cout<<"Before pushing : full: "<<isFull(sp)<<endl;
    cout<<"Before pushing : empty :"<<isEmpty(sp)<<endl;
    cout<<endl;
    cout<<endl;

    push(sp, 56);
    push(sp, 26);
    push(sp, 46);
    push(sp, 76);
    push(sp, 36);
    push(sp, 16);
    push(sp, 76);
    push(sp, 96);
    push(sp, 156);
    push(sp, 516);

    cout<<"After pushing : full :"<<isFull(sp)<<endl;
    cout<<"After pushing : empty :"<<isEmpty(sp)<<endl;

    cout<<"Popped "<<pop(sp)<<" from the stack \n";
    cout<<"Popped "<<pop(sp)<<" from the stack \n";
    cout<<endl;

    // Printing values from  the stack
    for(int j= 1; j <=sp -> top+1; j++)
    {
        cout<<"The value at position : "<<j<<" is : "<<peek(sp, j);
        cout<<endl;
    }


    return 0;
}