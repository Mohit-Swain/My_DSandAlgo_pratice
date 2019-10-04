#include"iostream"
using namespace std;
void print_array(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<", ";
	}
	cout<<endl;
}
void selection(int a[],int n){
   int i, j; 
   for(i=0;i<n;i++){
   		int min= i;
   		for(j=i+1;j<n;j++){
   			if(a[j]<a[min]){
   				min = j;
   			}
   		}
   		swap(a[min],a[i]);
   }
	print_array(a,n);
}

int main(){
	int t,n;

		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];

		selection(a,n);
}
