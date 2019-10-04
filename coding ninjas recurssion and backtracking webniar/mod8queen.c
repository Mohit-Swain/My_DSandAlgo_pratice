#include"stdio.h"
#define N 10
int isSolveable(int board[N][N],int i,int j){
	int x,y;
	for(x=0;x<i;x++){
		if(board[x][j]==1)
			return 0;
	}
	
	x = i;
	y = j;
	while(x>=0 && y>=0){
		if(board[x][y]==1){
			return 0;
		}
		x--;
		y--;
	}
	
	x=i;
	y=j;
	
	while(x>=0 && y<N){
		if(board[x][y]==1){
			return 0;
		}
		x--;
		y++;
	}
	
	return 1;
}

int solve8queen(int board[N][N],int i){
	int r,c;
	if(i>=N){
		for(r=0;r<N;r++){
			for(c=0;c<N;c++){
				if(board[r][c])
					printf("Q ");
				else
					printf("_ ");
			}
			printf("\n");
		}
		printf("\n");
		return 0;
	}
	
	int col;
	
	for(col = 0;col<N;col++){
		if(isSolveable(board,i,col)){
			board[i][col]=1;
			if(solve8queen(board,i+1))
				return 1;
			
			board[i][col]=0;		
		}
	}
	
	return 0;
}

int main(){
	int i,j;
	int board[N][N]={0};
	
	printf("%d",solve8queen(board,0));
}