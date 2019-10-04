#include"iostream"
using namespace std;
//Kadane's Algo
int main(){
	int i,n,a[1000],ms=0,cs=0;
	cout<<"enter no of elements in the array ";
	cin>>n;
	cout<<"\n enter the elements of the array :";
	for(i=0;i<n;i++){
		cin>>a[i];
	}

	//Kadane's algo for maximum subarray sum
	for(i=0;i<n;i++){
		cs=cs + a[i];
		if(cs<0)
			cs=0;
		ms = max(ms,cs);
	}

	cout<<ms;
}