#include"iostream"
using namespace std;
int rot_search(int a[],int n,int key){
	int l=0,r=n-1;
	while(l<=r){
		int mid = (l+r)/2;
		if(a[mid]==key)
			return mid;
		else if(a[l]<=a[mid]){
			if(key>=a[l] && key<=a[mid])
				r= mid-1;
			else
				l=mid+1;
		}
		else{
			if(key<=a[r] && key>=a[mid])
				l= mid+1;
			else
				r=mid-1;
		}

	}
	return -1;
}

int main(){
	int a[]={4,5,1,2,3},n=sizeof(a)/sizeof(a[0]);
	int key;
	cin>>key;
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl<<rot_search(a,n,key);
}