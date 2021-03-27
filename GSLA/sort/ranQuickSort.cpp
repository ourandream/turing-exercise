#include<iostream>
#include<ctime>
#define NUM 8000000

using namespace std;

int swap_times=0,comparison_time=0;

int ran_partition(int *a,int l,int r){
    if(l>=r){
        return r;
    }
    int t=rand()%(r-l+1)+l;
    swap_times++;
    swap(a[t],a[r]);

    int i=l-1;
    for(int j=l;j<r;++j){
        comparison_time++;
        if(a[j]<=a[r]){
            swap_times++;
            swap(a[++i],a[j]);
        }
    }
    swap_times++;
    swap(a[++i],a[r]);

    return i;
}

void qsort(int *a,int l,int r){
    if(l>=r){
        return;
    }
    int i = ran_partition(a,l,r);
    qsort(a,l,i-1);
    qsort(a,i+1,r);

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
    qsort(a,0,NUM-1);
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