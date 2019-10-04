#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *left,*right;

    node(int d){
        data = d;
        left = right = NULL;
    }
};
void bfs(node *root){
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        if(q.front()==NULL){
            q.pop();
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            node *f = q.front();q.pop();
            cout<<f->data<<" ";
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
}
void insert(node *&root,int d){
    if(root==NULL){
        root = new node(d);
        return ;
    }
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node *f = q.front();q.pop();
        if(f->left){
            q.push(f->left);
        }
        else{
            f->left = new node(d);
            return;
        }

        if(f->right){
            q.push(f->right);
        }
        else{
            f->right = new node(d);
            return;
        }
    }

}
void delete_tree(node *root){
    if(root==NULL){
        return ;
    }
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}
int main(){
    cout<<"Insert until you enter \"-1\" ";
    int d;
    node *head=NULL;
    while(1){
        cin>>d;
        if(d==-1){
            break;
        }
        insert(head,d);
    }
    bfs(head);
    delete_tree(head);
    return 0;
}