#include<iostream>
#include<ctime>

#define NUM 8000000

using namespace std;

void merge(int *arr,int left,int mid,int right,int *t){
    if(left>=right){
        return;
    }
    int i=left,j=mid+1,k=0;
    for(;i<=mid && j<=right;k++){
        if(arr[i]<=arr[j]){
            t[k]=arr[i++];
        }
        else{
            t[k]=arr[j++];
        }
    }
    if(i<=mid){
        while(i<=mid){
            t[k++]=arr[i++];
        }
    }
    if(j<=right){
        while(j<=right){
            t[k++]=arr[j++];
        }
    }
    for(int i=0;i<right-left+1;++i){
        arr[left+i]=t[i];
    }

    return;
}

void merge_sort(int* arr,int left,int right,int *t){
    if(left>=right){
        return;
    }
    int mid=(left+right)/2;
    merge_sort(arr,left,mid,t);
    merge_sort(arr,mid+1,right,t);
    merge(arr,left,mid,right,t);
}

int main(){
    int *a=new int[NUM];
    int *t=new int[NUM];
    FILE *fi=fopen("test.txt","r");
    for(int i=0;i<NUM;++i){
        fscanf(fi,"%d",&a[i]);
    }
    fclose(fi);

    clock_t start,end;
    start=clock();
    merge_sort(a,0,NUM-1,t);
    for(int i=0;i<500;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    end=clock();
    cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
    
    cout<<endl;
    delete a;
    delete t;

    return 0;
}