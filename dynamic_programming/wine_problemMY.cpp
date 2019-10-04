#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
int TD(int price[],int s,int e,int y,int memo[][5]){
    if(s>e){
        return 0;
    }
    if(memo[s][e]!=-1)  return memo[s][e];
    int inc1,inc2;
    inc1 = price[s]*y + TD(price,s+1,e,y+1,memo);
    inc2 = price[e]*y + TD(price,s,e-1,y+1,memo);
    memo[s][e] = max(inc1,inc2);
    return memo[s][e];
}
int BU(int price[],int n){
    int dp[100][100];
    int year = n;
    for(int i=0;i<n;i++){
        dp[i][i] = year*price[i];
    }
    year--;
    for(int len=2;len<=n;len++){
        int srt=0;
        int end = n-len;
        while(srt<=end){
            int endWindow = srt + len -1;
            dp[srt][endWindow] = max(
                price[srt]*year+dp[srt+1][endWindow],
                price[endWindow]*year + dp[srt][endWindow-1]
            );
            ++srt;
        }
        year--;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(3)<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][n-1];
}
int main(){
    int price[] = {1,4,2,3};
    int n = sizeof(price)/sizeof(int);
    int memo[5][5];
    memset(memo,-1,sizeof(memo));
    int ans = TD(price,0,n-1,1,memo);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(3)<<memo[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<ans<<endl;
    cout<<BU(price,4)<<endl;
}