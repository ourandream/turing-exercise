#include<stdio.h>

void MergeArray(int array[],int first,int mid,int last,int temp[]){
    int i,j,m,n;
    int k=0;
    i=first;j=mid+1;//两个合并的数组的起点
    m=mid;n=last;//两个合并的数组的终点
    while (i<=m && j<=n)//两个数组最小值比较，小的一方填入临时数组
    {
        if(array[i]<array[j]){
            temp[k++]=array[i++];
        }
        else{
            temp[k++]=array[j++];
        }
    }

    while (i<=m)//如果两个数组比较完有剩下，全部填入临时数组
    {
        temp[k++]=array[i++];
    }
    while (j<=n)
    {
        temp[k++]=array[j++];
    }
    for(i=0;i<k;++i){
        array[first+i]=temp[i];
    }
    
    return;
}

void Mergesort (int array[],int first,int last,int temp[]){
    if(first<last){
        int mid=(first+last)/2;
        Mergesort(array,first,mid,temp);
        Mergesort(array,mid+1,last,temp);
        MergeArray(array,first,mid,last,temp);
    }
    return;
}

int main(){
    int a[5]={6,3,7,2,5}, temp[10];
    Mergesort(a,0,4,temp);
    for(int i=0;i<5;++i){
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;
}