#include"iostream"
using namespace std;
int pivot(int a[],int n){
	int s=0,e=n-1;
	while(s<=e){
		int m = (s+e)/2;
		if(s<m && a[m]<a[m-1])
			return m-1;
		if(m<e && a[m+1]<a[m])
			return m;
		if(a[s]<=a[m])
			s= m+1;
		else
			e=m-1;
	}
	return n-1;	//for unrotated arrays
}

int main(){
	int a[]={1,2,3,4,5},n=sizeof(a)/sizeof(a[0]);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl<<pivot(a,n);
}