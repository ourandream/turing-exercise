//利用分治法解决找出一个数组的最大子序列的问题，即找出一个和最大的子数组

#include<iostream>
#include<limits>

using namespace std;

//主要的思路是将数组分为两部分,找出左右两边的最大子数组,再找出经过中点的最大子数组

struct subarray{
    int left;
    int right;
    int sum;
};
//用于返回一个子数组的必要信息

//下面的函数用于找出经过中点的最大子数组
subarray find_max_crossing(int *array,int left,int right){
    int mid=(left+right)/2;

    int sum=0,left_max=INT_MIN,left_index;
    for(int i=mid;i>=left;--i){
        sum+=array[i];
        if(sum>left_max){
            left_max=sum;
            left_index=i;
        }
    }
    //找出索引为[i..mid]的最大的子数组

    sum=0;
    int right_max=INT_MIN,right_index;
    for(int i=mid+1;i<=right;++i){
        sum+=array[i];
        if (sum>right_max){
            right_max=sum;
            right_index=i;
        }
    }
    //找出索引为[mid..i]的最大的子数组

    subarray return_array;
    return_array.left=left_index;
    return_array.right=right_index;
    return_array.sum=left_max+right_max;

    return return_array;
}

//该函数找出最大子数组
subarray find_max_subarray(int *array,int left,int right){
    if(left==right){//数组只有一个时的情况
        subarray return_array;
        return_array.left=left,return_array.right=right;
        return_array.sum=array[left];
        return return_array;
    }
    else{
        //数组有多个时的情况,分别找出左右两边和经过中点的最大子数组,然后进行比较
        int mid=(left+right)/2;
        subarray left_max=find_max_subarray(array,left,mid);
        subarray right_max=find_max_subarray(array,mid+1,right);
        subarray cross_mid_max=find_max_crossing(array,left,right);

        if(left_max.sum>max(right_max.sum,cross_mid_max.sum)){
            return left_max;
        }
        else if(right_max.sum>max(left_max.sum,cross_mid_max.sum)){
            return right_max;
        }
        else{
            return cross_mid_max;
        }
    }
}

int main(){
    int a[5]={-1,-2,-1,4,5};
    subarray maxA=find_max_subarray(a,0,4);
    cout<<maxA.left<<" "<<maxA.right<<" "<<maxA.sum<<endl;
    
    return 0;
}