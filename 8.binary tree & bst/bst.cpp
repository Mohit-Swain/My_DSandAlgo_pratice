#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node *left;
	node *right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}	
};
node *insert_in_bst(node *root,int d){
	if(root==NULL){
		root = new node(d);
		return root;
	}
	if(root->data == d){
		return root;
	}
	else if(d < root->data){
		root->left = insert_in_bst(root->left,d);
	}
	else{
		root->right = insert_in_bst(root->right,d);
	}

	return root;
}
node *build_bst(node *root){
	int d;
	cin>>d;
	while(d!=-1){
		root = insert_in_bst(root,d);
		cin>>d;
	}
	return root;
} 
int height(node *root){
	if(root==NULL){
		return 0;
	}
	int ls = height(root->left);
	int rs = height(root->right);
	return max(ls,rs)+1;
}
//O(n^2)
int diameter(node *root){
	if(root==NULL){
		return 0;
	}
	int hl = height(root->left);
	int hr = height(root->right);
	int c1 = hl + hr +1;
	int c2 = diameter(root->left);
	int c3 = diameter(root->right);

	return max(c1,max(c2,c3));
}

//first is diameter ,second is height
//O(n)

pair<int,int> diameter_cum_height(node *root){
	pair<int,int> p;
	if(root==NULL){
		p.first=0;
		p.second=0;
		return p;
	}
	pair<int,int> left = diameter_cum_height(root->left);
	pair<int,int> right = diameter_cum_height(root->right);
	//height 
	p.second =max(left.second,right.second) + 1;
	int d = left.second + right.second + 1;
	p.first = max(d,max(left.first,right.first));
	return p;
}

void printlevel(node *root,int x){
	if(root==NULL){
		return;
	}
	if(x==1){
		cout<<root->data<<" ";
		return;
	}
	printlevel(root->left,x-1);
	printlevel(root->right,x-1);
}
void print_all_levels(node *root){
	int h = height(root);
	for(int i=1;i<=h;i++){
		printlevel(root,i);
		cout<<endl;
	}
}
void inorder(node *root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<",";
	inorder(root->right);
}
void BFS(node *root){
	std::queue<node *> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		if(q.front()==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			node *temp = q.front();
			q.pop();
			cout<<temp->data<<" ";
			if(temp->left!=NULL){
				q.push(temp->left);
			}
			if(temp->right!=NULL){
				q.push(temp->right);
			}
		}
	}
}
node *delete_node(node *root,int d){
	if(root==NULL){
		return NULL;
	}
	else if(d <root->data){
		root->left = delete_node(root->left,d);
	}
	else if(d > root->data){
		root->right = delete_node(root->right,d);
	}
	else{
		if(root->left==NULL && root->right==NULL){
			delete root;
			return NULL;
		}
		else if(root->left==NULL && root->right!=NULL){
			node *temp = root->right;
			delete root;
			return temp;
		}
		else if(root->left!=NULL && root->right==NULL){
			node *temp = root->left;
			delete root;
			return temp;
		}
		else{	// both the nodes are not empty
			//we are trying to find the inorder successor
			node *replace = root->right; 
			while(replace->left!=NULL){
				replace = replace->left;
			}
			root->data = replace->data;
			root ->right = delete_node(root->right,root->data);
			return root;
		}
	}
}
//top down approach
bool isbst(node *root,int min,int max){
	cout<<root->data;
	if(root==NULL){
		return true;
	}
	if(root->data>min && root->data <max && 
		isbst(root->left,min,root->data) && 
		isbst(root->right,root->data,max)){
		return true;
	}
	else{
		return false;
	}

}
node * flattern(node *root){
	if(root==NULL){
		return NULL;
	}
	else if(root->left==NULL && root->right==NULL){
		return root;
	}
	else if(root->left==NULL && root->right != NULL){
		node * head = flattern(root->right);
		root->right = head;
		return root;
	}
	else if(root->left != NULL && root->right==NULL){
		node * head = flattern(root->left);
		node *tail = head;
		while(tail->right!=NULL){
			tail = tail->right;
		}
		tail->right = root;
		return head;
	}
	else{
		node *left = flattern(root->left);
		node *right = flattern(root->right);

		node *tail = left;
		while(tail->right!=NULL){
			tail = tail->right;
		}

		tail->right = root;
		root->right = right;
		return left;
	}
}
int main(){
	node *root=NULL;
	root = build_bst(root);
	inorder(root);
	cout<<endl;
	//print_all_levels(root);
	BFS(root);
	/*cout<<diameter(root)<<endl;
	cout<<height(root)<<endl;
	pair<int,int> dh = diameter_cum_height(root);
	cout<<dh.first<<" "<<dh.second<<endl;*/
	int d;
	cin>>d;
	//delete_node(root,d);
	cout<<endl;
	BFS(root);
	cout<<isbst(root,INT_MIN,INT_MAX);

	cout<<endl;
	node *head = flattern(root);
	//traverse
	while(head!=NULL){
		cout<<head->data<<"-->";
		head = head->right;
	}
	return 0;
}




























