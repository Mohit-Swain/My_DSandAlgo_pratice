#include <iostream>
#include <cstring>
#define mod 1000003
using namespace std;
int fact(int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    int smallfact = fact(n-1);
    return (n*smallfact)%mod;
}
int dict(char s[],int f[],int ans,int n){
    if(n==0){
        return ans;
    }
    int i,t=n,ans2=0;
    int c=0;
    for(int i=0;i<(s[0]-'a');i++){
        c+=f[i];
    }
    ans += (c*fact(t-1));
        ans %= mod;
    f[s[0]-'a']--;
    return dict(s+1,f,ans,n-1);
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    char s[30];
	    cin>>s;
        int n=strlen(s);
	    int f[26]={0};
        for(int i=0;s[i]!='\0';i++){
            f[s[i]-'a']++;
        }
	    cout<<1+dict(s,f,0,n)<<endl;
	}
	return 0;
}
