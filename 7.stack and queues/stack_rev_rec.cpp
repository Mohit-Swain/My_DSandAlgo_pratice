#include<iostream>
#include<stack>
using namespace std;
void insert_at_bottom(stack<int>&s,int d){
	if(s.empty()){
		s.push(d);
		return;
	}
	int temp = s.top();
	s.pop();
	insert_at_bottom(s,d);
	s.push(temp);
}
void rev_rec(stack<int> &s){
	if(s.empty())
	{
		return;
	}
	int temp = s.top();
	s.pop();
	rev_rec(s);
	insert_at_bottom(s,temp);
}
int main(){
	stack<int> s;
	for(int i=1;i<=5;i++){
		s.push(i);
	}
	rev_rec(s);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}