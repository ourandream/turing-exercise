#include<stdio.h>

int price[100];

int max(int a,int b){
    if(a<b){
        return b;
    }
    else{
        return a;
    }
}

void printcut(int s[],int N){
    while(N>0){
        printf("%d ",s[N]);
        N-=s[N];
    }
    printf("\n");
}

int top_down_memoried(int N,int p[],int r[],int s[]){
    if(r[N]>=0){
        return r[N];
    }
    if(N==0){
        r[N]=0;
        return r[N];
    }
    else{
        int q=-1;
        for(int i=1;i<=N;++i){
            q=max(q,p[i]+top_down_memoried(N-i,p,r,s));
            if(q>r[N]){
                r[N]=q;
                s[N]=i;
            }
        }
        return r[N];
    }
}

int top_down(int N,int p[]){
    int r[N+1],s[N+1];
    for(int i=0;i<=N;++i){
        r[i]=-1;
    }

    int result=top_down_memoried(N,p,r,s);
    printcut(s,N);
    return result;
}

int bottom_up(int N,int p[]){
    int r[N+1],s[N+1];
    r[0]=0;
    int q;
    for(int i=1;i<=N;++i){
        r[i]=-1;
    }
    for(int l=1;l<=N;++l){
        q=-1;
        for(int i=1;i<=l;++i){
            q=max(q,p[i]+r[l-i]);
            if(q>r[l]){
                r[l]=q;
                s[l]=i;
            }
        }
    }
    printcut(s,N);
    return r[N];
}

int main(){
    int N;
    scanf("%d",&N);
    price[0]=0;
    for(int i=1;i<=N;++i){
        scanf("%d",&price[i]);
    }
    printf("%d\n",top_down(N,price));
    printf("%d\n",bottom_up(N,price));

    return 0;
}