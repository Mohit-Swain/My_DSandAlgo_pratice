/*Given heights of n towers and a value k.
 We need to either increase or decrease height of every tower by k (only once) where k > 0.
 The task is to minimize the difference between the heights
 of the longest and the shortest tower after modifications, and output this difference.*/
//Made with love by MOHIT SWAIN
#include"iostream"
using namespace std;
int findMax(int a[],int n){
	int max =a[0];
	for(int i=1;i<n;i++)
		if(a[i]>max){
			max = a[i];
		}

	return max;
}

int findMin(int a[],int n){
	int min = a[0];
	for(int i=1;i<n;i++)
		if(a[i]<min){
			min = a[i];
		}

	return min;
}

int diff(int a[],int n){
	return (findMax(a,n) - findMin(a,n));
}
void print_array(int a[],int n){
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int back(int a[],int n,int k,int i,int m){
	//logic
	if(i==n){
		//print_array(a,n);
		return diff(a,n);
	}
	if(m==0)
		a[i]+=k;
	if(m==1)
		a[i]-=k;
	
	int x =min(back(a,n,k,i+1,0),back(a,n,k,i+1,1));
	//BACKTRACKING
	if(m==0)
		a[i]-=k;
	if(m==1)
		a[i]+=k;
	
	return x;

}

minimize_height(int a[],int n,int k){
	return min(back(a,n,k,0,0),back(a,n,k,0,1));
}

int main(){
	int arr[] = {1, 2,3} ,k = 2   ;
	cout<<minimize_height(arr,sizeof(arr)/sizeof(int),k);

}