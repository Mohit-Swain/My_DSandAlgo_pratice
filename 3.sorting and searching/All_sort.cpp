#include"iostream"
#include<algorithm>
using namespace std;
void show(int a[],int n){
	for(int i=0;i<n;i++)
		cout<<a[i]<<", ";
	cout<<endl;
}
void bubble(int a[],int n){
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<i;j++){
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
}

void bubble2(int a[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
}

void insertion(int a[],int n){
	int j;
	for(int i=1;i<n;i++){
		int temp = a[i];
		for(j=i-1;j>=0 && a[j]>temp;j--){
			a[j+1]=a[j];		//a[j+1]=a[j] cox you are making space by transfering it to the right
		}
		a[j+1]=temp;
	}
}

void selection(int a[],int n){
	for(int i=0;i<n;i++){
		int min = i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min])
				min=j;
		}
		swap(a[i],a[min]);
	}
}

int main(){
	int a[]= {9,6,4,2,5};
	show(a,sizeof(a)/sizeof(int));
	selection(a,sizeof(a)/sizeof(int));
	show(a,sizeof(a)/sizeof(int));
}