#include<iostream>
#include<cstring>
#define N 3
using namespace std;
int ans;
bool solve(int a[][N],int r,int c,int s,int f[]){
    if(r==1 && c==1){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        ans++;
        return true;
    }
    for(int i=1;i<10;i++){
        if(f[i]==0){
            a[r][c]=i;
            a[2-r][2-c]=s-i;
            f[i]=f[s-i]=1;
            if(c==2){
                solve(a,r+1,0,s,f);
            }
            else{
                solve(a,r,c+1,s,f);
            }
            a[r][c]=0;
            a[2-r][2-c]=0;
            f[i]=f[s-i]=0;
        }
    }
    return false;
}
int main(){
    int a[N][N]={0},f[10]={0};
    ans=0;
    a[1][1]=5;f[5]=1;
    solve(a,0,0,10,f);
    cout<<ans<<endl;
    return 0;
}