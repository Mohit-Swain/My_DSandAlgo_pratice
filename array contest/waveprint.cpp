#include"iostream"
using namespace std;

void waveprint(int arr[][10],int R,int C){
	int i,j;

	for(i=0;i<C;i++){
		if(i&1){
			for(j=R-1;j>=0;j--){
				cout<<arr[j][i]<<", ";
			}
		}
		else{
			for(j=0;j<R;j++){
				cout<<arr[j][i]<<", ";
			}
		}
	}
		cout<<"END";
	
}
int main(){
	int R,C,arr[10][10];
	cin>>R>>C;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>arr[i][j];
		}
	}

	waveprint(arr,R,C);
}