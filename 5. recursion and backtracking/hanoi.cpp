#include <iostream>
using namespace std;

void hanoi(int n,char start,char helper,char end){
	if(n==0){
		return;
	}

	hanoi(a,n-1,start,end,helper);
	cout<<"move "<<n<<" from "<<start<<" to "<<end"\n";
	hanoi(a,n-1,helper,start,end);
}

int main(){
	int n;
	cin>>n;

	hanoi(n,'A','B','C');

	return 0;
}