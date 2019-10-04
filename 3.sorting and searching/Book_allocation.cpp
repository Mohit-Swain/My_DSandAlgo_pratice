#include"iostream"
using namespace std;
int noofstudents(int a[],int n,int sum){
	for(int i=0;i<n;i++){
		if(a[i]>sum){
			return 0;
		}
	}
	int s=0,d=0,j=0;
	s++;
	while(j<n){
		d+=a[j];
		if(d>sum){
			d=0;
			s++;
		}
		else{
			j++;
		}
	}
	return s;
}

int mod_binary(int a[],int n,int N){
	int e=0,s=0;
	for(int i=0;i<n;i++){
		e+=a[i];
		if(a[i]>s){
			s=a[i];
		}
	}

	int ans,m;
	while(s<=e){
		m=(s+e)/2;
		if(noofstudents(a,n,m)==N){
			ans=m;
			e=m-1;
		}
		else if(noofstudents(a,n,m)>N){
			s=m+1;
		}
		else{
			e=m-1;
		}
	}
	return ans;
}

int main(){
	int a[]={10,20,30,40},n=sizeof(a)/sizeof(a[0]);
	cout<<mod_binary(a,n,2);
}