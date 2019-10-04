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
node *insert(node *h,int d){
    if(h==NULL){
        h = new node(d);
        return h;
    }
    if(d <= h->data){
        h->left = insert(h->left , d);
    }
    else{
        h->right = insert(h->right , d);
    }
    return h;
}
void preorder(node *head){
    if(head==NULL){
        return;
    }
    cout<<head->data<<" ";
    preorder(head->left);
    preorder(head->right);
}
/*void iter_preorder(node *head){
    queue<node*> q;
    q.push(head);
    while(!q.empty()){
        node *f = q.front();
        q.pop();
        cout<<f->data<<" ";
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
}*/
void inorder(node *h){
    if(h==NULL){
        return;
    }
    inorder(h->left);
    cout<<h->data<<" ";
    inorder(h->right);
}
void iter_inorder(node *head){
    stack<node *> s;
    node *curr = head;
    
    while(curr != NULL || !s.empty()){
        while(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }

        node *t = s.top();s.pop();
        cout<<t->data<<" ";
        
        curr = t->right;
    }
}
void postorder(node *head){
    if(head==NULL){
        return;
    }
    postorder(head->left);
    postorder(head->right);
    cout<<head->data<<" ";
}
void iter_postorder(node *head){
    stack<node *> s1,s2;
    s1.push(head);
    while(!s1.empty()){
        node* t = s1.top();s1.pop();
        s2.push(t);
        //cout<<t->data<<" ";
        if(t->left){
            s1.push(t->left);
        }
        if(t->right){
            s1.push(t->right);
        }
    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}
int main(){
    int a[] = {3,2,5,6,4};
    int n= sizeof(a)/sizeof(a[0]);
    node *head = NULL;
    for(int i=0;i<n;i++){
        head = insert(head,a[i]);
    }
    cout<<"PREORDER : "<<endl;
    preorder(head);
    cout<<endl;
    iter_preorder(head);
    cout<<endl<<"INORDER : "<<endl;
    inorder(head);
    cout<<endl;
    iter_inorder(head);
    cout<<endl<<"POSTORDER : "<<endl;
    postorder(head);
    cout<<endl;
    iter_postorder(head);
    return 0;
}