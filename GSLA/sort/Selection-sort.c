#include<stdio.h>

int * Selection_sort(int arr[],int len){
    int i,j,temp,min;
    for(i=0;i<len-1;++i){
        min=i;
        for(j=i+1;j<len-1;++j){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }

    return arr;
}

int main(){
    int arr[10],i,len=10;
    for(i=0;i<10;++i){
        scanf("%dd",&arr[i]);
    }
    Selection_sort(arr,len);
    for(i=0;i<10;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}