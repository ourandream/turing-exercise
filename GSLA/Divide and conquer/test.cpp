#include<limits.h>
#include<cstdio>

int max(int a,int b){
    return a>b?a:b;
}

int maxCrossMid(int *nums,int left,int right){
    int mid=(left+right)/2;
    int left_max=INT_MIN,right_max=INT_MIN;
    int sum=0;
    for(int i=mid;i>=left;--i){
        sum+=nums[i];
        if(sum>left_max){
            left_max=sum;
        }
    }
    sum=0;
    for(int i=mid+1;i<=right;++i){
        sum+=nums[i];
        if(sum>right_max){
            right_max=sum;
        }
    }

    return left_max+right_max;
}

int findMax(int *nums,int left,int right){
    if(left==right){
        return nums[left];
    }

    int mid=(left+right)/2;
    int left_max=findMax(nums,left,mid);
    int right_max=findMax(nums,mid+1,right);
    int cross_max=maxCrossMid(nums,left,right);

    if(left_max>max(right_max,cross_max)){
        return left_max;
    }
    else if(right_max>max(left_max,cross_max)){
        return right_max;
    }
    else{
        return cross_max;
    }
}

int maxSubArray(int* nums, int numsSize){
    return findMax(nums,0,numsSize-1);
}



int main(){
    int nums[4]={-1,-1,-2,-2};
    printf("%d\n",maxSubArray(nums,4));

    return 0;
}