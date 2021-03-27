#include<stdio.h>

int main(){
    int bagvol[6]={0,1,3,4,2,5};
    int bagpric[6]={0,2,3,4,5,6};
    int dp[6][6]={0};
    int temp;
    for(int i=1;i<=5;++i){
        for(int j=1;j<=5;++j){
            if(j-bagvol[i]<0){
                dp[i][j]=dp[i-1][j];
            }
            else{
                temp=bagpric[i]+dp[i-1][j-bagvol[i]];
                dp[i][j]=(dp[i-1][j]<temp?temp:dp[i-1][j]);
            }
        }
    }
    
    return 0;
}