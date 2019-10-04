#include"iostream"
using namespace std;

void print(int board[][100],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(board[i][j]==1){
				cout<<"Q ";
			}
			else{
				cout<<"_ ";
			}
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}
bool isvalid(int board[][100],int n,int r,int c){
	for(int i=0;i<r;i++){
		if(board[i][c]==1){
			return false;
		}
	}

	int i=r,j=c;
	while(i>=0 && j>=0){
		if(board[i][j]==1){
			return false;
		}
		i--;j--;
	}
	i=r,j=c;
	while(i>=0 && j<n){
		if(board[i][j]==1){
			return false;
		}
		i--;j++;
	}

	return true;
}

void magic(int n,int board[][100],int r,int c){
	if(r==n){
		print(board,n);
		return;
	}
	
	for(int i=c;i<n;i++)
	if(isvalid(board,n,r,i)){
		board[r][i]=1;
		magic(n,board,r+1,0);
		board[r][i]=0;
	}
}
void queen(int n){
	int board[100][100]={0};
	magic(n,board,0,0);
}
int main(){
	int n;
	cin>>n;
	queen(n);
}