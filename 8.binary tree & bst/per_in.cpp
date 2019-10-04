#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node *left;
        node *right;
    node(int d){
        data = d;
        left = right = NULL;
    }
};
int p=0;
node *createTree(int in[],int s,int e,int pre[]){
    if(s>e){
        return NULL;
    }

    int pivot = pre[p++];
    int i;
    for(i=s;i<=e;i++){
        if(in[i]==pivot){
            break;
        }
    }
    if(i==e+1){
        return NULL;
    }
    node *root = new node(pivot);
    root->left = createTree(in,s,i-1,pre);
    root->right = createTree(in,i+1,e,pre);
    return root;
}
void BFS(node *root){
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        if(temp==NULL){
            cout<<"\n";
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<' ';
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }

}
int main(){
    int in[8]={3,2,8,4,1,6,7,5},pre[8]={1,2,3,4,8,5,6,7};
    node *root = createTree(in,0,7,pre);
    BFS(root);
    return 0;
}