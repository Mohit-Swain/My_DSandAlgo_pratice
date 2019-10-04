//made with <3 by Mohit Swain//
#include"iostream"
using namespace std;

int main(){
	int arr[] = {2, 7, 9, 5, 8, 7, 4}, k = 5;
	int n = sizeof(arr)/sizeof(arr[0]);

	//logic
	int count=0,flag[n];
	for(int i=0;i<n;i++){
		if(arr[i]<=k){
			flag[i]=1;
			count++;
		}
		else{
			flag[i]=0;
		}
	}
	//sliding window
	int maxcount= 0,currcount=0;
	for(int i=0;i<=n-count;i++){
		currcount =0;
		for(int j=i;j<i+count;j++){
			if(flag[j]==1){
				currcount++;
			}
		}

		if(maxcount<currcount){
			maxcount=currcount;
		}
	}
		
		cout<<(count-maxcount);
}