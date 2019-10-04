#include"iostream"
using namespace std;
void print_array(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<", ";
	}
	cout<<endl;
}
void insertion(int a[],int n){
	int i, j; 
	for(i=1;i<n;i++){
		int temp = a[i-1];
		int min = n-1;
		for(j=n-1;j>=i;j--){
			if(a[j]<a[min]){
				min = j;
				
			}
		}
	}

	print_array(a,n);
}

int main(){
	int t,n;

		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];

		insertion(a,n);
}
