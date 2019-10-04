#include<bits/stdc++.h>
using namespace std;
int max_crossing_sum(int arr[] ,int n ,int m){
	int cs=0,ml=0,mr=0;
	for(int i = m  ;i >= 0 ;i-- ){
		cs += arr[i];
		if(cs > ml){
			ml = cs;
		}
	}

	cs = 0;
	for(int i = m + 1;i < n ;i++ ){
		cs += arr[i];
		if(cs > mr){
			mr = cs;
		}
	}

	return ml + mr;
}

int max_subarray_sum(int arr[] ,int n){
	if(n==1){
		return arr[0];
	}

	int mid = n/2;
	int c1 = max_subarray_sum(arr ,mid);
	int c2 = max_subarray_sum(arr + mid ,n-mid);
	int c3 = max_crossing_sum(arr ,n ,mid);

	return max(c3 ,max(c1 ,c2 ));
}
int main(){
	int arr[] = {2, 3, 4, 5, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout<<max_subarray_sum(arr, n);
}