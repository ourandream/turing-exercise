#include<stdio.h>

int binary_search(int arr[],int target,int len){//2分法查找一个数
    int start=0;
    int end=len-1;
    int mid;
    while(start<=end){
        mid=start+(end-start)/2;//mid=(end+start)/2 更可能溢出
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            start=mid+1;
        }
        else if(arr[mid]>target){
            end=mid-1;
        }
    }

    return -1;
}

int binary_searchleft(int arr[],int target,int len){//2分法查找左侧边界
    if(len==0){
        return -1;
    }
    int start=0;
    int end=len;
    int mid;
    while(start<end){
        mid=start+(end-start)/2;
        if(arr[mid]==target){
            end=mid;
        }
        else if(arr[mid]<target){
            start=mid+1;
        }
        else if(arr[mid]>target){
            end=mid;
        }
    }
    if(end==0){
        return -1;
    }

    return end;
}

int binary_searchright(int arr[],int target,int len){//2分法寻找右侧边界
    if(len==0){
        return -1;
    }
    int start=0;
    int end=len;
    int mid;
    while(start<end){
        mid=start+(end-start)/2;
        if(arr[mid]==target){
            start=mid+1;
        }
        else if(arr[mid]<target){
            start=mid+1;
        }
        else if(arr[mid]>target){
            end=mid;
        }
    }
    if(start==0){
        return -1;
    }

    return start-1;
}

int main(){
    int a[10]={1,2,4,4,5,6,8,10,14,15};
    printf("%d\n",binary_searchright(a,4,10));

    return 0;
}