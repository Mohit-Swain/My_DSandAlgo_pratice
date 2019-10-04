#include<iostream>
using namespace std;

int main(){
	int a = 10;
	cout<<&a<<endl;
	//no problem here
	// remember the output will be in hexadecimal form
	char ch = 'm';
	cout<<&ch;
	// output m here(problem)
	//its due to insertion operator
	// exception happens only in char type
	cout<<(void *)&ch<<endl;
	//explicit typecating from char * to void * to 
	//overcome the problem
}	