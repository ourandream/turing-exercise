#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
    return;
}

void bubblesort(int arr[],int len){
    int i,j,t;
    for(i=len;i>0;--i){
        for(j=0;j<i;++j){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }

    return;
}

void seletionsort(int arr[],int len){
    int min;
    int i,j;
    for(i=0;i<len-1;++i){
        min=i;
        for(j=i+1;j<len;++j){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(&arr[i],&arr[min]);
    }
    
    return;
}

void insertionsort(int arr[],int len){
    int current,preinsert;
    for(int i=1;i<len;++i){
        current=arr[i];
        preinsert=i-1;
        while(preinsert>=0 && arr[preinsert]>current){
            arr[preinsert+1]=arr[preinsert];
            preinsert--;
        }
        arr[preinsert+1]=current;
    }

    return;
}

void mergearray(int arr[],int first,int mid,int last){
    int temp[last+1];
    int i=first,j=mid+1;
    int arr1end=mid,arr2end=last;
    int k=0;
    while(i<=arr1end && j<=arr2end){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else if(arr[i]>=arr[j]){
            temp[k++]=arr[j++];
        }
    }
    while(i<=arr1end){
        temp[k++]=arr[i++];
    }
    while(j<=arr2end){
        temp[k++]=arr[j++];
    }
    for(i=0;i<k;++i){
        arr[first+i]=temp[i];
    }

    return;
}
void mergesort(int arr[],int first,int last){
    if(first<last){
        int mid=(first+last)/2;
        mergesort(arr,first,mid);
        mergesort(arr,mid+1,last);
        mergearray(arr,first,mid,last);
    }
    
    return;
}

void quicksort(int arr[],int left,int right){
    if(left>=right){
        return;
    }
    int i=left,j=right;
    int base=arr[left];
    while(i!=j){
        while(i<j && arr[j]>base){
            j--;
        }
        swap(&arr[i],&arr[j]);
        while(i<j && arr[i]<base){
            i++;
        }
        swap(&arr[i],&arr[j]);
    }
    quicksort(arr,left,i-1);
    quicksort(arr,i+1,right);

    return;
}

int main(){
    int arr[5];
    int i;
    srand((unsigned)time(NULL));
    for(i=0;i<5;++i){
        arr[i]=rand()%1000;
    }
    //bubblesort(arr,5);
    //seletionsort(arr,5);
    //insertionsort(arr,5);
    //mergesort(arr,0,4);
    quicksort(arr,0,4);
    for(i=0;i<5;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}