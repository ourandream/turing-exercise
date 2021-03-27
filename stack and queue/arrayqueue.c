#include<stdio.h>
#define MAX 100

typedef struct queue{
    int arr[MAX];
    int front;
    int last;
}queue;

queue creatnqueue(int n){
    queue new;
    new.arr[0]=1;
    for(int i=1;i<n;++i){
        new.arr[i]=new.arr[i-1]+1;
    }
    new.front=0;
    new.last=n-1;

    return new;
}

void inqueue(queue * que){
    if(que->last==MAX){
        printf("queue is full\n");
        return;
    }
    que->arr[que->last+1]=que->arr[que->last]+1;
    que->last+=1;
}

void outqueue(queue * que){
    que->front+=1;
}

void printqueue(queue que){
    for(int i=que.front;i<=que.last;++i){
        printf("%d ",que.arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    queue example=creatnqueue(n);
    inqueue(&example);
    outqueue(&example);
    printqueue(example);

    return 0;
}