#include"stdio.h"
int findpath2(int maze[][20],int n, int x, int y, int path[][20]){
	if(x<0 || x>=n || y<0 || y>=n){
		return 0;
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
		return 0;
	}
	
	if(maze[x][y] == 0 || path[x][y]==1){
		return 0;
	}
	
	path[x][y]=1;
	
	//Right
		if(findpath2(maze, n,x, y+1,path)){
			//path[x][y]=0;
			return 1;
		}
	//Left
		if(findpath2(maze,n,x,y-1,path)){
			//path[x][y]=0;
			return 1;
		}
	//Top
		if(findpath2(maze,n,x-1,y,path)){
			//path[x][y]=0;
			return 1;
		}
	//Bottom
		if(findpath2(maze,n,x+1,y,path)){
			//path[x][y]=0;
			return 1;
		}
		
		path[x][y]=0;
		return 0;
}

int findpath(int maze[][20], int n){
	int path[20][20] = {0};
	int x=0,y=0;
	return findpath2(maze,n,x,y,path);
	
}

int main(){
	int n=3;
	int maze[20][20]={{1,1,0},{1,1,0},{0,1,1}};
	printf("%d",findpath(maze,n));
}