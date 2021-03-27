#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int item;
    struct stack* back;
}stack;

void push (stack** example,int item){
    stack* temp = (stack *)malloc(sizeof(stack));
    temp->item=item;
    temp->back=*example;
    *example=temp;
}

void pop (stack** example){
    if((*example)->back == NULL){
        printf("stack now empty\n");
        free(*example);
        return;
    }
    stack* temp=(*example)->back;
    free(*example);
    *example=temp;

}

int main(){
    stack* example=NULL;
    push(&example,5);
    push(&example,6);
    pop(&example);
    pop(&example);
    //printf("%d\n",example->item);

    return 0;
}
