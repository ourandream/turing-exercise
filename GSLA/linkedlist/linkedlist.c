#include<stdio.h>
#include<stdlib.h>

typedef struct node *link;
struct node
{
    int item;
    link next;
    link pre;
};

int Josephus (int N,int M){
    link x=malloc(sizeof*x),t=x;
    int i;
    for(i=2;i<=N;++i){
        x=(x->next=malloc(sizeof*x));
        x->item=i;
        x->next=t;
    }
    while(x->next!=x){
        for(i=1;i<M;i++){
            x=x->next;
        }
        x->next=x->next->next;
    }

    return x->item;
}

int main(){
    link x=malloc(sizeof*x);
    link t=malloc(sizeof*t);
    link i=malloc(sizeof*i);
    x->next=i;
    t->next=x->next;
    x->next=t;//增加节点
    t->item=1;
    i->item=2;
    x->item=3;
    i->pre=x;
    t->pre=i->pre;
    i->pre=t;
    //x->next=x->next->next;减少节点
    link temp=x;
    /*while(1){//遍历链表
        printf("%d ",temp->item);
        if(temp->next!=NULL){
            temp=temp->next;
        }
        else{
            break;
        }
    }
    printf("\n");*/
    printf("%d\n",Josephus(9,5));
    printf("%d\n",i->pre->item);
    free(x);
    free(t);
    free(i);
    return 0;
}
