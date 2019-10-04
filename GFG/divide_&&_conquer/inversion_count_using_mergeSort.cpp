#include"iostream"
using namespace std;

int merge(int a[],int s,int mid,int e){
	int b[e-s+1]={0},inv_count =0;
	int m = mid-s;
	int i=s,j=mid+1,k=0;
	while(i<=mid && j<=e){
		if(a[i]<=a[j]){
			b[k]= a[i++];
		}
		else{
			b[k] = a[j++];
			inv_count += (mid + 1 -i);	//why coz all the numbers from i to mid are greater than the no in j
		}
		k++;
	}
	while(i<=mid){
		b[k++]=a[i++];
	}
	while(j<=e){
		b[k++] = a[j++];
	}
	for(int i=s;i<=e;i++){
		a[i] = b[i-s];
	}

	return inv_count;
}
int mergesort(int a[],int s,int e){
	if(e<=s){
		return 0;
	}
	int inv_count=0,mid=(s+e)/2;
	inv_count += mergesort(a,s,mid);
	inv_count += mergesort(a,mid+1,e);
	inv_count += merge(a,s,mid,e);
	return inv_count;
}

int main(){
	int arr[]={2,4,1,3,5},n = sizeof(arr)/sizeof(arr[0]);
	int inv = mergesort(arr,0,n-1);
	cout<<inv<<endl;
}