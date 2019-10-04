//1 x : Right Circular Shift the array x times. If an array is a[0], a[1], …., a[n – 1], 
//then after one right circular shift the array will become a[n – 1], a[0], a[1], …., a[n – 2].
//2 y : Left Circular Shift the array y times. If an array is a[0], a[1], …., a[n – 1],
// then after one right circular shift the array will become a[1], …., a[n – 2], a[n – 1], a[0].
//3 l r : Print the sum of all integers in the subarray a[l…r] (l and r inclusive).
#include"iostream"
using namespace std;

void querytype1(int *toRotate,int times,int n){
	//right
	(*toRotate) = ((*toRotate)-times)%n;	//minus sign bcoz note the first element in the array is going back

}

void querytype2(int *toRotate,int times,int n){
	//left
	(*toRotate) = ((*toRotate)+times)%n;

}

void querytype3(int toRotate,int left,int right,int arr[],int n){
	int ans;

	left = (toRotate + left + n)%n;
	right = (toRotate + right + n)%n;

	if(left <= right){
		ans = (arr[right]  - arr[left-1]);
	}
	else{
		ans = (arr[n-1] +(arr[right] - arr[left-1]));	//see arr[n-1] plus sign bcoz the thing right to plus sign is -ve 
	}
	cout<<ans<<endl;

}

int wrapper(int arr[],int n){
	int preSum[n];
	preSum[0] = arr[0];
	for(int i=1;i<n;i++){
		preSum[i]=arr[i]+preSum[i-1];
	}

	int toRotate = 0; 
  
    querytype1(&toRotate, 3, n); 
    querytype3(toRotate, 0, 2, preSum, n); 
    querytype2(&toRotate, 1, n); 
    querytype3(toRotate, 1, 4, preSum, n); 
} 

int main(){
	int a[]={1,2,3,4,5};
	int n = sizeof(a)/sizeof(a[0]);

	wrapper(a,n);
}
