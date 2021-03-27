#include<iostream>
#include<ctime>

#define NUM 8000000

using namespace std;

int swap_times=0,comparison_time=0;

int hoare_partition(int *a,int l,int r){
    if(l>=r){
        return r;
    }
    int key=a[l];
    int i=l-1,j=r+1;
    while(1){
        comparison_time++;
        do{
            j--;
            comparison_time++;
        }while(a[j]>key);
        comparison_time++;
        do{
            i++;
            comparison_time++;
        }while(a[i]<key);
        if(i<j){
            swap_times++;
            swap(a[i],a[j]);
        }
        else{
            return j;
        }
    }
}

void quickSort(int *a,int l,int r){
    if(l>=r){
        return;
    }
    int k=hoare_partition(a,l,r);
    quickSort(a,l,k);//注意这个partitio使得左右两个数组有大小关系，中间那个数不一定是中间量
    quickSort(a,k+1,r);

    return;
}

int main(){
    int *a=new int[NUM];
    FILE *fi=fopen("test.txt","r");
    for(int i=0;i<NUM;++i){
        fscanf(fi,"%d",&a[i]);
    }
    fclose(fi);

    clock_t start,end;
    start=clock();
    quickSort(a,0,NUM-1);
    for(int i=0;i<500;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    end=clock();
    cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
    
    cout<<endl;
    cout<<"swap time:"<<swap_times<<",comparison time:"<<comparison_time<<endl;
    delete a;
    
    return 0;
}