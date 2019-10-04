#include"stdio.h"
#include"math.h"
int check(int board[][4],int row,int col){
	int i,j;
	for(i=0;i<4;i++){
		if(board[row][i]==1)
			return 0;
		
		if(board[i][col]==1)
			return 0;
	}
	
	int s = abs(row - col);
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(abs(i-j)==s && board[i][j]==1)
				return 0;
			
	return 1;
}

int queen(int board[][4],int n,int row,int col){
	int i,j;
	if(check(board,row,col))
		return 0;
	if(n==4){
		return 1;
	}
	for(i=row;i<4;i++){
		for(j=col;j<4;j++){
			board[i][j]=1;
			
			if(queen(board,n+1,row+1,0)){
				return 1;
			}
			
			board[i][j]=0;
		}
	}
	
	return 0;
}

int main(){
	int i,j;
	int board[4][4] ={0};
	printf("%d ",queen(board,0,0,0));
}