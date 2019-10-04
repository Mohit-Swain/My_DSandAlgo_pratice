#include"iostream"
using namespace std;

void waveprint(int arr[][10],int R,int C){
	int i=0,j=0;
	while(j<C){
		while(i>=0 && i<R){
			if(j%2==0){
				cout<<arr[i][j]<<" ";
				i++;
			}
			else{
				cout<<arr[i][j]<<" ";
				i--;
			}
		}
		j++;

		if(i==R)
			i=R-1;
		else
			i=0;
	}
}

int main()
{
	int arr[][10]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	waveprint(arr,3,4);
	return 0;
}