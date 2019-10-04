#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<char>&s1,stack<char>&s2,int n){
	for(int i=0;i<n;i++){
		int temp = s1.top();
		s1.pop();
		s2.push(temp);
	}
}
int main(){
	stack<char>s1,s2;
	int n;
	cin>>n;
	if(n>26){
		cout<<"invalid ";
		return 0;		
	}
	for(int i=65;i<65 + n;i++){
		s1.push(i);
	}
	
	for(int i=0;i<n;i++){
		int temp = s1.top();
			s1.pop();
		int nvacant = n-1-i;
		transfer(s1,s2,nvacant);
		s1.push(temp);
		transfer(s2,s1,nvacant);
	}
	while(!s1.empty()){
		cout<<s1.top()<<" ";
		s1.pop();
	}
	return 0;
}