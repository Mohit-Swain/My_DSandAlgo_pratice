#include"iostream"
#define N 5
using namespace std;

class Queue
{
	int arr[N];
	int r,f;
public:
	Queue(){
		r=f=-1;
	}
	void push(int data){
		if(r==-1 && f==-1){
			r = f =0;
			arr[r]=data;
			r = (r+1)%N;
		}

		else if(!empty()){
			arr[r]=data;
			r = (r+1)%N;
		}
		else{
			cout<<"Queue is full "<<endl;
		}
	}
	
	int pop(){
		int m;
		if(!empty()){
			 m = arr[f];
			f = (f+1)%N;
		}
		return m;
	}

	bool empty(){
		if(r==f){
			cout<<"Queue is empty "<<endl;
			return true;
		}
		return false;
	}
};
int main(){
	int n,data;
	Queue q;
	do{
		cin>>n;
		if(n==1){
			cout<<"enter data ";
			cin>>data;
			q.push(data);
		}
		else if (n==2)
		{
			cout<<q.pop()<<endl;
		}
	}while(n!=0);
	return 0;
}