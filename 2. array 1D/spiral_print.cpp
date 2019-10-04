//Made with <3 by Mohit Swain
#include"iostream"
#define N 5
using namespace std;

void spiral(int a[][10]){
	int startrow =0,startcol=0,endrow=N-1,endcol=N-1;
	while(startrow<=endrow || startcol <=endcol){
		//print_row(a,startrow,startcol,endcol);
		for(int i=startcol;i<=endcol;i++){
			cout<<a[startrow][i]<<" ";
		}
		startrow++;
		//print_col(a,endcol,startrow,endrow);
		for(int i=startrow;i<=endrow;i++){
			cout<<a[i][endcol]<<" ";
		}
		endcol--;
		//print_row(a,endrow,endcol,startcol);
		for(int i=endcol;i>=startcol;i--){
			cout<<a[endrow][i]<<" ";
		}
		endrow--;
		//print_col(a,startcol,endrow,startrow);
		for(int i=endrow;i>=startrow;i--){
			cout<<a[i][startcol]<<" ";
		}
		startcol++;
	}
}
int main(){
	int a[][10]={{ 1, 2, 3, 4, 5},
				 { 6, 7, 8, 9,10},
				 {11,12,13,14,15},
				 {16,17,18,19,20},
				 {21,22,23,24,25}};
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n\n";

	spiral(a);
}