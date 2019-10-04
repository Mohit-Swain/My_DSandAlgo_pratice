#include"iostream"
using namespace std;

int kadanes(int a[],int n){
	int currSum=0,maxSum=0,i,low,high;
	for(i=0;i<n;i++){
		currSum += a[i];

		if(currSum<0){
			currSum =0;
			low = i+1;
		}

		if(currSum>maxSum){
			maxSum = currSum;
			high = i;
		}
	}
	cout<<"low is "<<low<<" high is "<<high<<endl;

	return maxSum;
}

int main(){
	int arr[]= {-1, 40, -14, 7, 6, 5, -4, -1},n=sizeof(arr)/sizeof(arr[0]);
	cout<<kadanes(arr,n);
}