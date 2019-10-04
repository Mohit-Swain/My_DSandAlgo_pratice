#include"stdio.h"

int canPlace(int board[][9],int n,int row,int col){
	int srow,scol,i,j;
	for(i=0;i<9;i++){
		if(board[row][i]==n)
			return 0;
		
		if(board[i][col]==n)
			return 0;
	}
	
	srow = row - row%3;
	scol = col - col%3;
	
	for(i=srow;i<srow+3;i++){
		for(j=scol;j<scol+3;j++){
			if(board[i][j]==n)
				return 0;
		}
	}
	
	return 1;
}

int sudoku(int board[][9])
{
	int i,j,num;
	int isEmpty=0;
	int row=-1,col=-1;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(board[i][j]==0){
				isEmpty=1;
				row =i;
				col =j;
				break;
			}
		}
		if(isEmpty)
			break;
	}
	
	if(isEmpty ==0 ){
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				printf("%d ",board[i][j]);
			}
			printf("\n");
		}
		return 1;
	}
	for(num=1;num<=9;num++){
		if(canPlace(board,num,row,col)){
			board[row][col] =num;
			if(sudoku(board)){
				return 1;
			}
			board[row][col]=0;
		}
	}
	return 0;
}
int main(){
	int board[9][9]= {{0,4,0,1,7,0,8,0,9},
					  {0,0,0,0,0,5,0,4,7},
					  {0,0,0,0,3,0,1,0,0},
					  {0,7,0,9,0,0,0,3,0},
					  {9,0,1,0,0,0,4,0,6},
					  {0,2,0,0,0,7,0,1,0},
					  {0,0,7,0,5,0,0,0,0},
					  {2,3,0,7,0,0,0,0,0},
					  {4,0,5,0,9,3,0,2,0}};
					
	printf(" %d",sudoku(board));
}







