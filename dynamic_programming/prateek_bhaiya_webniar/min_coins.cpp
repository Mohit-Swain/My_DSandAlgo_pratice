#include<iostream>
#include<climits>
using namespace std;
int minCoins(int coins[],int n,int amount){
    if(amount==0){
        return 0;
    }
    int ans = INT_MAX;
    for(int i=0;i<3;i++){
        if(amount-coins[i]>=0){
            int smallAns = minCoins(coins,n,amount - coins[i]);
            if(smallAns!=INT_MAX){
                ans = min(ans,smallAns+1);
            }
        }
    }
    return ans;
}
int minCoinsBU(int coins[],int n,int amount){
    int *dp = new int[amount+1];
    dp[0] = 0;

    for(int i=1;i<=amount;i++){
        dp[i] = INT_MAX;
        for(int j=0;j<n;j++){
            if(coins[j]<=i){
                int smallAns = dp[i - coins[j]];
                if(smallAns!=INT_MAX){
                    dp[i] = min(dp[i],smallAns +1);
                }
            }
        }
    }
    return dp[amount];
}
int main(){
    int coins[] = {1,2,3};
    int n = 3;
    int amount = 15;
    cout<<minCoinsBU(coins,n,amount)<<endl;
    return 0;
}