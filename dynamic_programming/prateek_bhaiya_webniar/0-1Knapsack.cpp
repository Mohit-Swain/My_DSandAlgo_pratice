#include<iostream>
#include<climits>
using namespace std;
int knapsack(int wt[],int price[],int n,int W){
    if(n==0||W==0){
        return 0;
    }
    int inc = 0,exc =0;
    inc = price[n-1] + knapsack(wt,price,n-1,W - wt[n-1]);
    exc = knapsack(wt,price,n-1,W);

    return max(inc,exc);
}
int knapsackBU(int wt[],int price[],int N,int W){
    int dp[100][100];
    for(int i=0;i<=N;i++){
        for(int w=0;w<=W;w++){
            if(i==0||w==0){
                dp[i][w] =0;
            }
            else{
                int inc = 0,exc =0;
                inc = price[i-1] + dp[i-1][W - wt[i-1]];
                exc = 0 + dp[i-1][W];

                dp[i][w] = max(inc,exc);
            }
        }
    }
    return dp[N][W];
}
int main(){
    int wt[] = {2,7,3,4};
    int price[] = {55,20,20,10};

    int n =4;
    int w = 11;
    int maxProfit = knapsack(wt,price,n,w);
    cout<<maxProfit<<endl;   
    cout<<knapsackBU(wt,price,n,w)<<endl; 
    return 0;
}