#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
class Heap{
	std::vector<int> v;
	bool minHeap;

	bool compare(int a,int b){
		if(minHeap){
			return v[a]>v[b];
		}
		else{
			return v[a]<v[b];
		}
	}

	void heapify(int i){
		int left = 2*i;
		int right = 2*i+1;
		int minIndex = i;
		if(left<v.size() && compare(minIndex,left)){
			minIndex = left;
		}
		if(right<v.size() && compare(minIndex,right)){
			minIndex = right;
		}

		if(minIndex!=i){
			swap(v[i],v[minIndex]);
			heapify(minIndex);
		}

		return;
	}
public:
	Heap(bool type=true){
		v.push_back(-1);
		minHeap = type;
	}

	void push(int data){
		v.push_back(data);
		int index = v.size()-1;
		int parent = index/2;
		while(index>1 && compare(parent,index)){
			swap(v[index],v[parent]);
			index = parent;
			parent = parent/2;
		}
	}

	int top(){
		if(v.size()>1){
			return v[1];
		}
		else{
			cout<<"heap empty"<<endl;
			return -1;
		}
	}

	bool empty(){
		return v.size()==1;
	}

	void pop(){
		int last = v.size()-1;
		swap(v[1],v[last]);
		v.pop_back();
		heapify(1);
	}
};
int main(){
	Heap h;
	int d;
	cin>>d;
	while(d!=-1){
		h.push(d);
		cin>>d;
	}

	cout<<endl;
	while(!h.empty()){
		cout<<h.top()<<",";
		h.pop();
	}

	return 0;
}