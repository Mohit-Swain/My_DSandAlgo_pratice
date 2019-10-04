#include"stdio.h"
void findpath2(int maze[][20],int n, int x, int y, int path[][20]){
	if(x<0 || x>=n || y<0 || y>=n){
		return;
	}
		
    if(x== n-1 && y== n-1){
		int i,j;
		path[x][y]=1;
		
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%d ",path[i][j]);
			}
			printf("\n");
		}
		printf("------------------------------\n");
		return;
	}
	
	if(maze[x][y] == 0 || path[x][y]==1){
		return;
	}
	
	path[x][y]=1;
	
	//Right
		findpath2(maze, n,x, y+1,path);
	//Left
		findpath2(maze,n,x,y-1,path);
	//Top
		findpath2(maze,n,x-1,y,path);
	//Bottom
		findpath2(maze,n,x+1,y,path);
		
		path[x][y]=0;
}

void findpath(int maze[][20], int n){
	int path[20][20] = {0};
	int x=0,y=0;
	findpath2(maze,n,x,y,path);
	
}

int main(){
	int n=3;
	int maze[20][20]={{1,1,0},{1,1,0},{0,1,1}};
	findpath(maze,n);
}