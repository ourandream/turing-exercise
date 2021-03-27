#include<stdio.h>

int * Insertion_sort(int arr[],int len){
    int i,current,preindex;
    for(i=1;i<len;++i){
        current=arr[i];
        preindex=i-1;
        while (preindex>=0 && arr[preindex]>current)
        {
            arr[preindex+1]=arr[preindex];
            preindex--;
        }
        arr[preindex+1]=current;
        
    }

    return arr;
}

int main(){
    int arr[20];
    int i;
    for(i=0;i<5;++i){
        scanf("%d",&arr[i]);
    }
    Insertion_sort(arr,5);
    for(i=0;i<5;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}