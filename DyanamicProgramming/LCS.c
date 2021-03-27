#include<stdio.h>

int printLCS(int *b,int n,int X[],int i,int j){
    if(!i || !j){
        return 0;
    }
    int temp;
    temp=b[i*n+j];
    if(temp==1){
        printLCS(b,n,X,i-1,j-1);
        printf("%d ",X[i]);
    }
    else if(temp==2){
        printLCS(b,n,X,i-1,j);
    }
    else{
        printLCS(b,n,X,i,j-1);
    }

    return 0;
}

int lcs(int se1[],int len1,int se2[],int len2){
    int c[len1+1][len2+1];
    int b[len1+1][len2+1];
    c[0][0]=0;
    for(int i=1;i<=len1;++i){
        c[i][0]=0;
    }
    for(int j=1;j<=len2;++j){
        c[0][j]=0;
    }
    for(int i=1;i<=len1;++i){
        for(int j=1;j<=len2;++j){
            c[i][j]=0;
            if(se1[i]==se2[j]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
            }
            else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]=2;
            }
            else{
                c[i][j]=c[i][j-1];
                b[i][j]=3;
            }
        }
    }
    printLCS(&b[0][0],len2+1,se1,len1,len2);
    printf("\n");

    return c[len1][len2];
}

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int sequence1[m+1],sequence2[n+1];
    for(int i=1;i<=m;++i){
        scanf("%d",&sequence1[i]);
    }
    for(int i=1;i<=n;++i){
        scanf("%d",&sequence2[i]);
    }
    printf("%d\n",lcs(sequence1,m,sequence2,n));

    return 0;
}