#include"iostream"
#include"cstring"
#include <cmath>
#define ll long long
using namespace std;

int main(){
	int l,u;
	cin>>l>>u;
	bool  a[u-l+1],p[(int)sqrt(u)+1];
	int n = sqrt(u);
	memset(a,true,sizeof(a));
	memset(p,true,sizeof(p));
	for(int i=2;i<=n;i++){
		if(p[i]){
			for(int j=i*i;j<=n;j+=i){
				if(j%i==0){
					p[j]=false;
				}
			}
		}
	}

	for(int i=2;i<=n;i++){
		if(p[i]){
			for(int j=l;j<=u;j++){
				if(j%i==0){
					a[j-l]=false;
				}
			}
		}
	}
	for(ll j=l;j<=u;j++){
		if(a[j-l]==true){
			cout<<j<<" ";
		}
	}
	return 0;
}