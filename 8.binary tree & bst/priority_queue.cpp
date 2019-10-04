#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

int main()
{
	int a[] = {5,6,17,18,9,11};
	priority_queue<int,std::vector<int>,greater<int> > pq(a,a+6);
	while(!pq.empty()){
		cout<<pq.top()<<",";
		pq.pop();
	}

	return 0;
}