#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node *link;

	node(int d){
		data = d;
		link = NULL;		
	}
};
void print(node *head){
	while(head!=0){
		cout<<head->data<<"->";
		head = head->link;
	}
}
void push_front(node *&head ,int data){
	node *n = new node(data);
	if(n==NULL){
		cout<<"memory full!!!";
		return;
	}
	n->link = head;
	head = n;
}

void push_mid(node*&head,int data,int pos = 0){
	if(head == NULL && pos!=0){
		cout<<"invalid index "<<endl;
		return;
	}
	if(pos==0){
		push_front(head,data);
	}
	else{
		int c = pos-1;
		node *temp = head;
		while(c>0){
			temp= temp->link;
			if(temp==NULL){
				cout<<"invalid index "<<endl;
				return;
			}
			c--;
		}

		node *n = new node(data);
		if(n==NULL){
			cout<<"memory full!!!";
			return;
		}	
		n->link = temp->link;
		temp->link = n;
	}
}
void push_back(node *&head , int data){
	if(head == NULL){
		push_front(head,data);
		return;
	}
	node *temp = head;
	while(temp->link!=NULL)temp = temp->link;
	node *n = new node(data);
	if(n==NULL){
		cout<<"memory full!!!";
		return ;
	}
	temp->link = n;
	return ;
}
int menue(){
	cout<<endl;
	cout<<"1 to push_front"<<endl;
	cout<<"2 to push_mid"<<endl;
	cout<<"3 to push_back"<<endl;
	cout<<"4 to print "<<endl;
	cout<<"0 to quit"<<endl;
	int option;
	cout<<"enter your option ";
	cin>>option;
	return option;
}
int main(){
	//insert
	node *head = NULL;
	while(1){
		int option = menue();
		if(option==0)
			break;
		
		int data;
		
		if(option==1){
			cout<<"enter data ";
			cin>>data;
			push_front(head,data);
		}
		else if (option==2)
		{
			int pos;
			cout<<"enter data ";
			cin>>data;
			cout<<endl<<"enter position ";
			cin>>pos;
			push_mid(head,data,pos);
		}
		else if(option==3){
			cout<<"enter data ";
			cin>>data;
			push_back(head,data);
		}
		else if(option==4){
			print(head);
		}
		else{
			cout<<"invalid option "<<endl;
		}
	}
	print(head);
	
}