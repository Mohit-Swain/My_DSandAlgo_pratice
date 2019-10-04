#include<iostream>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    long long s=0;
    for(int i=0;i<m;i++){
        int o=0;
        for(int j=0;j<n;j++){
            o+=a[j][i];
            //cout<<i<<" "<<j<<endl;
        }
        o = max(o,n-o);
        //cout<<o<<endl;
        s+= o*(1<<(m-i-1));
    }
    cout<<s<<endl;
    return 0;
}