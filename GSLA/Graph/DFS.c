#include<stdio.h>

typedef struct vertex
{
    int start;
    int end;
    int color;
    int pi;
}vertex;
typedef struct Graph
{
    int gra[100][100]; 
}Graph;

int time=0;

int DFS_Visit(Graph testGraph,vertex *test,int n,int v){
    time++;
    test[v].start=time;
    test[v].color=1;

    for(int i=0;i<6;++i){
        if(testGraph.gra[v][i]){
            if(!test[i].color){
                test[i].pi=v;
                DFS_Visit(testGraph,test,n,i);
            }
        }
    }

    time++;
    test[v].end=time;
    test[v].color=2;

    return 0;
}

int DFS(Graph testGraph,vertex *test,int n){
    for(int i=0;i<6;++i){
        test[i].color=0;
    }
    for(int i=0;i<6;++i){
        if(!test[i].color){
            test[i].pi=-1;
            DFS_Visit(testGraph,test,n,i);
        }       
    }

    return 0;
}

int main(){
    Graph testGraph={
        {{0,1,0,1,0,0},
        {0,0,0,0,1,0},
        {0,0,0,0,1,1},
        {0,1,0,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,0,0,1}}
    };
    vertex test[6];
    DFS(testGraph,test,6);

    return 0;
}