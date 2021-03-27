#include<stdio.h>
#include<stdbool.h>

typedef struct array{
    int a[10000];
    int c;
}primearray,array;

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

int lcm(int a,int b){
    return a/gcd(a,b)*b;//a*b可能溢出？
}

array prime(int range){
    array prime;
    int vic[range+1];
    prime.c=0;
    for(int i=0;i<=range;++i){
        vic[i]=1;
    }
    for(int i=2;i<=range;++i){
        if(vic[i]){
            prime.a[prime.c++]=i;
            for(int j=i*2;j<=range;j+=i){
                vic[j]=0;
            }
        }
    }

    return prime;
}

bool is_Prime(int a){
    array isPrime=prime(a);
    if(isPrime.a[isPrime.c-1]==a){
        return true;
    }
    else{
        return false;
    }
}

void printPrime(int arrange){
    array Prime=prime(arrange);
    for(int i=0;i<Prime.c;++i){
        printf("%d ",Prime.a[i]);
    }
    printf("\n");
}

int main(){
    /*int a,b;
    scanf("%d %d",&a,&b);
    printf("%d %d\n",gcd(a,b),lcm(a,b));*/
    /*int a;
    scanf("%d",&a);
    if(is_Prime(a)){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }*/
    int arrange;
    scanf("%d",&arrange);
    printPrime(arrange);

    return 0;
}