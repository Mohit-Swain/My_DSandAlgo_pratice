#include<bits/stdc++.h>
using namespace std;
void show(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<",";
	}
	cout<<endl;
}
int main(){
	int a[] ={7,3,2,6,1,4,8};
	int n = sizeof(a)/sizeof(a[0]);
	cout<<"max element is "<<*max_element(a,a+n)<<endl;	//note *
	cout<<"min element is "<<*min_element(a,a+n)<<endl;
	cout<<"sum is "<<accumulate(a,a+n,0)<<endl;	//to find the sum of vectors
	cout<<"count of 3 is "<<count(a,a+n,3)<<endl;
	cout<<"find test of 3 "<<*find(a,a+n,11)<<endl;	//returns hexadecimal address

	sort(a,a+n);
	show(a,n);
	reverse(a,a+n);
	show(a,n);
	a.erase(4);
	show(a,n);
}