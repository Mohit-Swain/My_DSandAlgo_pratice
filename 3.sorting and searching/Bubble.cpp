#include"iostream"
using namespace std;
void print_array(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<", ";
	}
	cout<<endl;
}
void bubble(int a[],int n){
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(arr[j], arr[j+1]); 

	print_array(a,n);
}

int main(){
	int t,n;

		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];

		bubble(a,n);
}
