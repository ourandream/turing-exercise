#include<stdio.h>

int swap(int *p,int *q){
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}

void quicksort(int arr[],int left,int right){
    if(left>=right){
        return;
    }
    
    int i,j,temp;
    temp=arr[left];
    i=left;
    j=right;

    while(i!=j){
        while (i<j && arr[j]>=temp)
        {
            j--;
        }
        swap(&arr[i],&arr[j]);
        while (i<j && arr[i]<=temp)
        {
            i++;
        }
        swap(&arr[i],&arr[j]);
    }

    quicksort(arr,left,i-1);
    quicksort(arr,i+1,right);
    
    return;
}

int main(){
    int a[5]={1,3,4,2,5};
    quicksort(a,0,4);
    for(int i=0;i<5;++i){
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;
}