#include"iostream"
using namespace std;

int main(){
	int a[4][4]={{1,4,8,10},
				 {2,5,9,15},
				 {6,16,18,20},
				 {10,18,19,23}};
	int i=0,j=3,n;
	cin>>n;
	while(1){
		if(i<0 || j<0){
			cout<<"not found";
			return 0;
		}
		if(n==a[i][j]){
			cout<<"found at "<<i<<" "<<j;
			return 0;
		}
		if(n<a[i][j]){
			j--;
		}
		if(n>a[i][j]){
			i++;
		}
	}
}