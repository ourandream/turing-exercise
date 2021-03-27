#include<stdio.h>

typedef struct vertex
{
    int color;
    int d;
    int pi;
}vertex;
typedef struct Graph
{
    int gra[100][100];
}Graph;


void BFS(Graph testGraph,vertex *test,int n,int s){
    for(int i=0;i<n;++i){
        test[i].color=0;
        test[i].d=-1;
        test[i].pi=-1;
    }
    test[s].color=1;
    test[s].d=0;
    test[s].pi=-1;
    
    int queue[n];
    int front=-1,rear=-1;
    queue[++rear]=s;
    while(front!=rear){
        int temp=queue[++front];
        test[temp].color=1;
        for(int i=0;i<n;++i){
            if(testGraph.gra[temp][i]){
                if(!test[i].color){
                    test[i].color=1;
                    test[i].d=test[temp].d+1;
                    test[i].pi=temp;
                    queue[++rear]=i;
                }
            }
        }
        test[temp].color=2;      
    }
}

void printPath(vertex *test,int s,int v){
    if(v==s){
        printf("%d ",s);
    }
    else if(test[v].pi==-1){
        printf("No path\n");
    }
    else{
        printPath(test,s,test[v].pi);
        printf("%d ",v);
    }
}

int main(){
    vertex test[10];
    Graph testGraph={
        {{0,1,0,1,0,0},
        {0,0,0,0,1,0},
        {0,0,0,0,1,1},
        {0,1,0,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,0,0,1}}
    };
    BFS(testGraph,test,6,0);
    printPath(test,0,4);
    printf("\n");

    return 0;
}