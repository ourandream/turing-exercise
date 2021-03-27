#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* bubble_sort(int arr[],int len){//冒泡排序
    int t;
    for(int i=len-1;i>0;--i){
        for(int j=0;j<=i;++j){
            if(arr[j]>arr[j+1]){
                t=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=t;
            }
        }
    }

    return arr;
}

int* selection_sort(int arr[],int len){//选择排序
    int t;
    int min=0;
    int i,j;
    for(i=0;i<len-1;++i){
        min=i;
        for(j=i;j<len;++j){
            if(arr[j]<arr[min]){
               min=j; 
            }
        }
        t=arr[i];
        arr[i]=arr[min];
        arr[min]=t;
    }

    return arr;
}

int *insertion_sort(int arr[],int len){//插入排序
    int current,insert,i;
    for(i=1;i<len;++i){
        current=arr[i];
        insert=i-1;
        while(insert>=0 && arr[insert]>current){
            arr[insert+1]=arr[insert];
            insert--;
        }
        arr[insert+1]=current;
    }

    return arr;
}
void merge_array(int arr[],int first,int mid,int last){
    int temp[last+1];
    int i=first,j=mid+1;
    int m=mid,n=last;
    int k=0;
    while(i<=m && j<=n){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while (i<=m){
        temp[k++]=arr[i++];
    }
    while (j<=n){
        temp[k++]=arr[j++];
    }
    for(i=0;i<k;++i){
        arr[first+i]=temp[i];
    }

    return;
}
void merge_sort (int arr[],int first,int last){//归并排序
    if(first<last){
        int mid=(first+last)/2;
        merge_sort(arr,first,mid);
        merge_sort(arr,mid+1,last);
        merge_array(arr,first,mid,last);
    }
    
    return;
}

void swap(int *x,int *y){
    int t=*x;
    *x=*y;
    *y=t;
    return;
}
void quicksort(int arr[],int left,int right){//快速排序
    if(left>=right){
        return;
    }

    int i,j,temp;
    temp=arr[left];
    i=left;
    j=right;

    while(i!=j){
        while(i<j && arr[j]>temp){
            j--;
        }
        swap(&arr[i],&arr[j]);
        while(i<j && arr[i]<temp){
            i++;
        }
        swap(&arr[i],&arr[j]);
    }

    quicksort(arr,left,i-1);
    quicksort(arr,i+1,right);

    return;
}


int main (){
    int *a;
    a=(int *)malloc(sizeof(int)*5);
    srand((unsigned)time(NULL));
    for(int i=0;i<5;++i){
        a[i]=rand()%100;
    }
    //bubble_sort(a,5);
    //selection_sort(a,5);
    //insertion_sort(a,5);
    merge_sort(a,0,4);
    //quicksort(a,0,4);
    for(int i=0;i<5;++i){
        printf("%d ",a[i]);
    }
    printf("\n");
    free(a);

    return 0;
}