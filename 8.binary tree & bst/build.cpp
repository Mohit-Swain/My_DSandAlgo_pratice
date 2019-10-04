#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

class node
{
public:
	int data;
	node *left;
	node *right;

	node(int d){
		data = d;
		left=NULL;
		right=NULL;
	}	
};

node* build_tree(){
	int d;
	cin>>d;

	if(d==-1){
		return NULL;
	}

	node *root = new node(d);
	root->left = build_tree();
	root->right = build_tree();

	return root;
}

void preorder(node *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(node *root){
	if(root==NULL){
		return;
	}
	preorder(root->left);
	cout<<root->data<<" ";
	preorder(root->right);
}

void BFS(node *root){	//O(n)
	queue<node *> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node *n = q.front();
		q.pop();
		if(n==NULL){
			cout<<endl;
			if(!q.empty())
				q.push(NULL);
		}
		else{
			cout<<n->data<<" ";
			if(n->left!=NULL)
				q.push(n->left);
			if(n->right!=NULL)
				q.push(n->right);
		}
	}

}
void postorder(node *root){
	if(root==NULL){
		return;
	}
	preorder(root->left);
	preorder(root->right);
	cout<<root->data<<" ";
}

int height(node *root){
	if(root==NULL)
		return 0;

	int ls = height(root->left);
	int rs = height(root->right);

	return max(ls,rs) + 1;
}
void printNthNode(node *root,int c){
	if(c==1){
		cout<<root->data<<" ";
		return;
	}
	if(root->left!=NULL)
		printNthNode(root->left,c-1);
	if(root->right!=NULL)
		printNthNode(root->right,c-1);

}
void printAllNode(node *root){	//O(n^2)
	int H = height(root);
	for(int i=1;i<=H;i++){
		printNthNode(root,i);
		cout<<endl;
	}
}
int count(node *root){
	if(root==NULL)
		return 0;
	return 1+count(root->left)+count(root->right);
}
int sum(node *root){
	if(root==NULL)
		return 0;
	return root->data+sum(root->left)+sum(root->right);
}
int sumReplacer(node *root){
	if(root==NULL){
		return 0;
	}
	int leftsum =sumReplacer(root->left);
	int rightsum = sumReplacer(root->right);
	int d = root->data;
	if(leftsum==0 && rightsum==0){
		return d;
	}
	root->data = leftsum + rightsum;
	return d + leftsum + rightsum;
}
int isHeightBalanced(node *root){
	if(root==NULL){
		return 0;
	}
	int leftheight = isHeightBalanced(root->left);
	int rightheight = isHeightBalanced(root->right);

	if(leftheight==-1 || rightheight==-1){
		return -1;
	}

	if(abs(leftheight - rightheight)<=1){
		return max(leftheight,rightheight) + 1;
	}
	else{
		return -1;
	}
}
node *buildTreeFromArray(int a[],int s,int e){
	if(s>e){
		return NULL;
	}

	int mid = (s+e)/2;
	node *root = new node(a[mid]);

	root->left = buildTreeFromArray(a,s,mid-1);
	root->right = buildTreeFromArray(a,mid+1,e);

	return root;
}
int main(){
	int a[] = {1,2,3,4,5,6,7};
	int n = sizeof(a)/sizeof(a[0]);

	node *root = buildTreeFromArray(a,0,n-1);
	BFS(root);
	
	
	return 0;
}