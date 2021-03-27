#include<stdio.h>
#include<stdlib.h>

int **return_arr()
{
    int **arr=(int **)malloc(sizeof(int *)*2);
    int i,j;
    for(i=0;i<2;i++)//checking purpose
    {
        arr[i]=(int *)malloc(sizeof(int)*2);
        for(j=0;j<2;j++)
        {
            arr[i][j]=i*10+j;
        }
    }
    return arr;
}
int ** matrixmultiply(int **a,int **b){
    int product[2][2];
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            for(int k=0;k<2;++k)
            product[i][j]+=a[i][k]*b[k][j];
        }
    }

    return product;
}

void diaplay(int matrix[][2]){
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    diaplay(matrixmultiply(Q,Q));
    return 0;
}