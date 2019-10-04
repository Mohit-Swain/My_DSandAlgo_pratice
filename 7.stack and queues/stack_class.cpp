#include<iostream>
#include<vector>
#include <stack>
using namespace std;

template <typename T>
class Stack
{
	std::vector<T> v;
public:
	void push(T data){
		v.push_back(data);
	}

	void pop(){
		if(!empty()){
			v.pop_back();
		}
	}

	bool empty(){
		return v.empty();
	}

	T top(){
		return v.back();
	}
	
};
int main(){
	Stack<int>s;
	for(int i=1;i<=5;i++){
		s.push(i*i);
	}

	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}