//Bottomup
//1D dp
#include<iostream>
using namespace std;
int waysBU(int n,int k){
    int *dp = new int[n+1];
    dp[0] = 1;

    for(int step=1;step<=n;step++){
        dp[step] = 0;
        for(int j = 1;j<=k;j++){
            if(step-j >= 0){
                dp[step] += dp[step - j];
            }
            else{
                break;
            }
        }
    }
    return dp[n];
}//O(nk)
int ways2(int n,int k){ //to be seen
    int *dp = new int[n+1];
    dp[0] = 1;
    for(int step = 1;step<=n;step++){
        dp[step]= 2*dp[step-1];
        if(step-k-1>=0){
            dp[step]-=dp[step-k-1];
        }
    }

    return dp[n];
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<ways2(n,k)<<endl;
    return 0;
}