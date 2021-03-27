#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int item;
    struct queue* next;
    struct queue * last;
}queue;

queue* creatqueue(){
    queue* new=(queue *)malloc(sizeof(queue));
    new->item=1;
    new->last=new;
    new->next=NULL;

    return new;
}

void pushqueue(queue * que){
    queue* new=(queue *)malloc(sizeof(queue));
    new->item=que->last->item+1;
    new->next=NULL;
    que->last->next=new;
    que->last=new;
}

void popqueue(queue ** que){
    if((*que)->next==NULL){
        free(*que);
        printf("queue now empty\n");
        return;
    }
    queue * temp;
    temp =(*que)->next;
    free(*que);
    *que=temp;
}

void freequeue(queue * que){
    while(que->next!=NULL){
        free(que);
        que=que->next;
    }
    free(que);
}

void display (queue* que){
    while(que->next!=NULL){
        printf("%d ",que->item);
        que=que->next;
    }
    printf("%d\n",que->item);
}

int main(){
    queue * example=creatqueue();
    pushqueue(example);
    popqueue(&example);
    display(example);
    freequeue(example);

    return 0;
}