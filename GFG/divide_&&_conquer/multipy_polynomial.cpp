#include"iostream"
#include<cstring>
using namespace std;

int *sum(int a[],int b[],int n1,int n2){
	int *res = new int [max(n1,n2)];
	int i=0;
	for( i=0;i<n1 && i<n2 ; i++){
		res[i] = a[i] + b[i];
	}
	// while(i<n1){
	// 	res[i] = a[i];
	// 	i++;
	// }

	// while(i<n2){
	// 	res[i] = b[i];
	// 	i++;
	// }

	return res;
}

int *multiply(int A[], int B[], int n){
	if(n==1){
		int *ans = new int [1];
		ans[0] = A[0]*B[0];

		return ans;
	}
	int mid = n/2,a0[mid],a1[mid],b1[mid],b0[mid];
	for(int i=0;i<n;i++){
		if(i<mid){
			a0[i] = A[i];
			b0[i] = B[i];
		}
		else{
			a1[i-mid] = A[i];
			b1[i-mid] = B[i];
		}
	}

	int *a0b0 = multiply(a0,b0,mid); //2*mid - 1
	int *a1b1 = multiply(a1,b1,mid); //2*mid - 1
	int *abcd = multiply(sum(a0,a1,mid,mid),sum(b0,b1,mid,mid), mid); //2*mid - 1
	//subtract a0b0 + a1b1 from  abcd
	int *a0b0a1b1 = sum(a0b0,a1b1,2*mid - 1,2*mid - 1);
	for(int i=0;i< 2*mid-1;i++){
		a0b0a1b1[i] = -a0b0a1b1[i];
	}
	int *center_element = sum(abcd,a0b0a1b1,2*mid - 1,2*mid - 1);

	int *res = new int[2*n -1];

	memset(res,(2*n - 1)*sizeof(int),0);
	for(int i=0;i<2*n-1;i++)
		res[i] = 0;
	//put a0b0 in proper place
	for(int i=0;i<2*mid - 1; i++){
		cout<<a0b0[i]<<" ";
		res[i] += a0b0[i];
	}
	cout<<endl;
	//put center_element in proper place;
	for(int i=0;i<2*mid -1; i++){
		cout<<center_element[i]<<" ";
		res[mid + i] += center_element[i];
	}
	cout<<endl;

	//put a1b1 in its place
	for(int i=0;i<2*mid - 1;i++){
		cout<<a1b1[i]<<" ";
		res[n+ i] += a1b1[i];
	}
	cout<<endl;
	return res;
}
int main(){
	int A[] = {5, 0, 10, 6}; 
	int B[] = {1, 2, 4, 0}; 
    int m = sizeof(A)/sizeof(A[0]); 
    int n = sizeof(B)/sizeof(B[0]);
    int *p = multiply(A,B,n);

    for(int i=0;i<2*n -1 ;i++){
    	cout<<p[i]<<" ";
    }
}