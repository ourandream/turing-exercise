#include<stdio.h>

typedef struct matrix{
    int arr[100][100];
    int m;
    int n;
}matrix;

matrix matrixmul(matrix *a,matrix *b){//multiply two matrix
    matrix product;
    product.m=a->m;
    product.n=b->n;
    int temp;
    for(int i=0;i<product.m;++i){
        for(int j=0;j<product.n;++j){
            temp=0;
            for(int k=0;k<a->n;++k){
                temp+=a->arr[i][k]*b->arr[k][j];
            }
            product.arr[i][j]=temp;
        }
    }

    return product;
}

void printmatrix(matrix *matr){
    for(int i=0;i<matr->n;++i){
        for(int j=0;j<matr->m;++j){
            printf("%d ",matr->arr[i][j]);
        }
        printf("\n");
    }
}

void readmatrix(int m,int n,matrix *store,FILE * fin){
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            fscanf(fin,"%d",&store->arr[i][j]);
        }
    }
}

int main(){
    FILE *fin=fopen("./test.txt","r");
    matrix tes[2];
    int i=0;
    while(!feof(fin)){
        fscanf(fin,"%d",&tes[i].m);
        fscanf(fin,"%d",&tes[i].n);
        readmatrix(tes[i].m,tes[i].n,&tes[i],fin);
        i++;
    }
    matrix product=matrixmul(&tes[0],&tes[1]);
    printmatrix(&product);
    fclose(fin);
    
    return 0;
}