#include"iostream"
using namespace std;

void rotate(int a[][10],int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			swap(a[i][j],a[j][i]);
		}
	}
}
void initarray(int a[][10],int n){
	int value = 1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j] = value;
			value++;
		}
	}
}

void printarray(int a[][10],int n){
	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";		
		}
		cout<<endl;
	}	
}
int main(){
	int n;
	cin>>n;
	int a[10][10];
	initarray(a,n);
	printarray(a,n);
	rotate(a,n);
	printarray(a,n);
}