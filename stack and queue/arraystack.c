#include<stdio.h>
#define MAX 100

typedef struct stack{
    int arr[MAX];
    int top;
}stack;

stack creatstack(int n){
    stack new;
    new.arr[0]=1;
    for(int i=1;i<n;++i){
        new.arr[i]=new.arr[i-1]+1;
    }
    new.top=n-1;

    return new;
}

void pushstack(stack * que){
    if(que->top==MAX){
        printf("stack is full\n");
        return;
    }
    que->arr[que->top+1]=que->arr[que->top]+1;
    que->top+=1;
}

void popstack(stack *que){
    if(que->top==0){
        printf("stack is empty\n");
        return;
    }
    que->top--;
}

void printfstack (stack que){
    for(int i=0;i<=que.top;++i){
        printf("%d ",que.arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    stack example=creatstack(n);
    pushstack(&example);
    popstack(&example);
    printfstack(example);

    return 0;
}