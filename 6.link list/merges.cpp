#include"iostream"
using namespace std;
class node
{
	public:
	int data;
	node* link;

	node(int data){
		this->data = data;
		link = NULL;
	}
};
void printll(node *head){
	while(head!=0){
		cout<<head->data<<"->";
		head = head->link;
	}
	cout<<endl;
}
void createll(node *&head){
	cout<<"creating a link list(enter -1 to stop)";
	int data;
	cout<<"enter data ";
	cin>>data;
	node *temp = new node(data);
	head = temp;
	node *p=temp;
	while(1){
		cout<<"enter data ";
		cin>>data;
		if(data==-1){
			return;
		}
		node *n = new node(data);
		p->link=n;;
		p=n;
	}
}

node* merge(node* head1,node* head2){
	if(head1==0){
		return head2;
	}
	else if(head2==0)
		return head1;

	node *merged;
	if(head1->data < head2->data){
		 merged = merge(head1->link,head2);
		 head1->link = merged;
		 return head1;
	}
	else{
		merged = merge(head1,head2->link);
		head2->link = merged;
		return head2;
	}
}
node *findm(node *head){
	node *p=head;
	head = head->link;
	while(head!=0 && head->link!=0)
	{
		head=head->link->link;
		p=p->link;
	}
	return p;
}
node *mergesort(node *head){
	if(head->link==0 || head==0)
		return head;
	node *mid = findm(head);
	node *nextmid = mid->link;
	mid->link=0;
	head = mergesort(head);
	nextmid = mergesort(nextmid);

	return merge(head,nextmid);

}
int main(){
	node *head1=0,*head2=0;
	createll(head1);
	//createll(head2);
	printll(head1);
	//printll(head2);
	//node* head3 = merge(head1,head2);
	head2=mergesort(head1);
	printll(head2);
}