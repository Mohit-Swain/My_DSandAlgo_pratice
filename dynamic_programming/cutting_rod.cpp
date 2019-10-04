#include<iostream>
#include<climits>
using namespace std;
int BU(int price[],int n){
    int *dp = new int[n+1]{0};
    dp[1] = price[0];
    for(int i=2;i<=n;i++){
        int ans = INT_MIN;
        for(int j=1;j<=i;j++){  //no of things to choose;
            int smallans = price[j-1]+dp[i-j];
            ans = max(smallans,ans);
        }
        dp[i] = ans;
    }
    return dp[n];
}

//Rec
int maxRec(int price[],int n){
    if(n==0){
        return 0;
    }
    int best = 0;
    for(int len=1;len<=n;len++){
        int ans = price[len-1]+maxRec(price,n - len);
        best = max(best,ans);
    }
    return best;
}

int main(){
    int price[] = {1,3,2,5};
    int n = sizeof(price)/sizeof(int);
    int ans = BU(price,n);
    cout<<ans<<endl;
    cout<<maxRec(price,n)<<endl;
    return 0;
}