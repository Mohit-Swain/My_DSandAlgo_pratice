#include <iostream>
using namespace std;
//Recursion is a method where the solution to a problem depends on smaller solutions
bool isSorted(int a[],int n){
	if(n==1){
		return true;
	}

	if(a[0]<a[1]){
		return isSorted(a+1,n-1);
	}
	return false;
}

int fastPower(int a,int b){
	if(b==0){
		return 1;
	}
	int smallPower = fastPower(a,b/2);
	if(b%2==0){
		return smallPower * smallPower;
	}
	else{
		return a * smallPower * smallPower;
	}
}

void printInc(int n){
	if(n==0){
		return;
	}
	printInc(n-1);
	cout<<n<<' ';
}
void printDec(int n){
	if(n==0){
		return;
	}
	cout<<n<<' ';
	printDec(n-1);
}
int product(int x,int y){
    if (x < y) 
        return product(y, x); 
  
    else if (y != 0) 
        return (x + product(x, y - 1)); 
  
    else
        return 0; 
}
int toInt(char s[],int n){
	if(n==0){
		return 0;
	}
	int small = toInt(s+1,n-1);
	return fastPower(10,n-1)*(s[0]-'0')+small;
}
void bubble_sort_rec(int a[],int j,int n){
	if(n==1){
		return;
	}

	if(j==n-1){
		return bubble_sort_rec(a,0,n-1);
	}

	if(a[j]>a[j+1]){
		swap(a[j],a[j+1]);
	}

	bubble_sort_rec(a,j+1,n);
}
void subSequence(char a[],char b[],int j){
	if(a[0]=='\0'){
		b[j]='\0';
		cout<<b<<endl;
		return;
	}
	subSequence(a+1,b,j);
	b[j]=a[0];
	subSequence(a+1,b,j+1);
}
void permutations(char s[],int i){
	if(s[i]=='\0'){
		cout<<s<<endl;
		return;
	}

	for(int j=i;s[j]!='\0';j++){
		swap(s[i],s[j]);
		permutations(s,i+1);
		swap(s[i],s[j]);
	}

}
bool check(int a[][100],int n,int i,int j){
	//cout<<"jop";
	//check for columns
	for(int i1=0;i1<i;i1++){
		if(a[i1][j]==1){
			return false;
		}
	}

	//check digonal
	int i1 = i,j1 = j;
	while(i1>=0 && j1>=0){
		if(a[i1][j1]==1){
			return false;
		}
		i1--;j1--;
	}
	i1 = i,j1 = j;
	while(i1>=0 && j1<n){
		if(a[i1][j1]==1){
			return false;
		}
		i1--;j1++;
	}
	return true;
}
void print(int board[][100],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
}
bool queen(int n,int board[][100],int i){
	//cout<<"hi";
	if(i==n){
		print(board,n);
		return false;
	}
	for(int j=0;j<n;j++){
		if(check(board,n,i,j)){
			board[i][j]=1;
			bool b = queen(n,board,i+1);
			if(b==true){
				return true;
			}
			//backtrack
			board[i][j]=0;

		}
	}
	return false;
}

void solveQueen(int n){
	int board[100][100]={0};
	bool b = queen(n,board,0);
	if(b==true){
		print(board,n);
	}
	else{
		cout<<"Impossible"<<endl;
	}
}
int main(){
	int a1[]={1,2,4,6,8,11},a2[]={2,1,6,5,7,4,8};
	int n1 = sizeof(a1)/sizeof(int),n2 = sizeof(a2)/sizeof(int);
	char s[] = "abc",b[100];
	int n ;
	cin>>n;
	solveQueen(n);
	return 0;
}