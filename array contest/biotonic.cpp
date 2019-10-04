// subarray is first increasing and then decreasing or entirely increasing or decreasing.
#include"iostream"
using namespace std;
int biotonic(int a[],int n){
	int ai[n]={0},ad[n]={0};

	ai[0]=1;
	for(int i=1;i<n;i++){
		if(a[i]>a[i-1]){
			ai[i]=ai[i-1]+1;
		}
		else{
			ai[i]=1;
		}
	}
	
	ad[n-1]=1;
	for(int i=n-2;i>=0;i--){
		if(a[i]>a[i+1]){
			ad[i] = ad[i+1]+1;
		}
		else{
			ad[i] = 1;
		}
	}
	
	int m=0;
	for(int i=0;i<n;i++){
		if(m<(ai[i]+ad[i]-1)){
			m = ai[i]+ad[i]-1;
		}
	}

	return m;
}
int main(){
	int t;
	cin>>t;
	while(t--)
	{	int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int k=biotonic(a,n);
				
		cout<<k<<endl;
	}
}