#include <iostream>
// #include <stdlib.h>

using namespace std;

struct stack{
    int size;
    int top;
    int *arr;
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

int main(){
    // ONE METHOD
    // struct stack s;
    // s.size = 20;
    // s.top = -1; //empty array top is -1
    // s.arr = (int*) malloc(s.size * sizeof(int));

    //2ND METHOD
    struct stack *s;
    s -> size =20;
    s -> top = -1;
    s -> arr = (int*)malloc(s->size * sizeof(int));

    //pushing an element manually
    s -> arr[0] = 7;
    s -> top++;

    //check if stack is empty
    if(isEmpty(s)){
        cout<<"The stack is empty ";
    }
    else{
        cout<<"The stack is not empty ";
    }


    return 0;
}