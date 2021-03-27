#include<iostream>
#include<ctime>

#define NUM 10000
#define MAX 8000000

using namespace std;

void counting_sort(int *arr,int len,int k){
	int *temp1=new int[k+1];
	int *temp2=new int[len];
	for(int i=0;i<=k;++i){
		temp1[i]=0;
	}
	for(int i=0;i<len;++i){
		temp1[arr[i]]++;
	}
	for(int i=1;i<=k;++i){
		temp1[i]+=temp1[i-1];
	}
	for(int i=len-1;i>0;--i){
		temp2[temp1[arr[i]]-1]=arr[i];
		temp1[arr[i]]--;
	}
	for(int i=0;i<len;++i){
		arr[i]=temp2[i];
	}
	delete []temp1;delete []temp2;
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
    counting_sort(a,NUM,MAX);
    for(int i=0;i<500;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    end=clock();
    cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
    
    cout<<endl;
    delete a;

	return 0;
}