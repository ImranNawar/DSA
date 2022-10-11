#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray * a, int tSize, int uSize)
{
    // (*a).total_size = tSize;      //dereference
    // (*a).used_size  = uSize;
    // (*).ptr = (int *) malloc(tSize*sizeof(int)); //return integer pointer to that memory block which we reserved in heap

                         //the below is same to it 

    a->total_size = tSize;      //dereference
    a->used_size  = uSize;
    a->ptr = (int *) malloc(tSize*sizeof(int)); //return integer pointer to that memory block which we reserved in heap
}


void show(struct myArray *a){
    for(int i =0; i < a->used_size;i++ )
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

void setVAL(struct myArray *a)
{
    int n;
    for(int i =0; i < a->used_size;i++ )
    {
        printf("Enter element %d", i);
        scanf(" %d ", &n);
        (a->ptr)[i]=n;
    }
}
int main()
{
    struct myArray marks;
    createArray(&marks, 100, 20);
    show(&marks);
    setVAL(&marks);
    return 0;
}