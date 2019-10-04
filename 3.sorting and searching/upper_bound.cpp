#include"iostream"
using namespace std;

int upper(int a[],int n,int u){
	int s=0,e=n-1,ans=-1;
	while(s<=e){
		int m = (s+e)/2;
		if(a[m]==u){
			ans = m;
			s=m+1;
		}
		else if(u<a[m]){
			e=m-1;
		}
		else{
			s=m+1;
		}
	}
	return ans;
}
int main(){
	int a[]={1,2,2,2,2,4,4},n=sizeof(a)/sizeof(a[0]);
	int u;
	cin>>u;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl<<upper(a,n,u);
}