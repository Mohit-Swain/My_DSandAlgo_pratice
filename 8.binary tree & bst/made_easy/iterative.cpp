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
void iter_preorder2(node *head){
    stack<node *>s;
    while(1){
        while(head){
            cout<<head->data<<" ";
            s.push(head);
            head = head->left;
        }
        if(s.empty()){
            break;
        }
        head = s.top(); s.pop();
        head = head->right;
    }
}
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
void iter_postorder2(node *head){
    stack<node *> s;
    node *prev = NULL;
    do{
        while(head!=NULL){
            s.push(head);
            head = head->left;
        }

        while(head==NULL && !s.empty()){
            head = s.top();
            if(head->right == NULL || head->right == prev){
                cout<<head->data<<" ";
                s.pop();
                prev = head;
                head = NULL;
            }
            else{
                head = head->right;
            }
        }

    }while(!s.empty());
}

void level_order(node *root){
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
int main(){
    int a[] = {3,5,2,7,2,0,4,1,3};
    int n= sizeof(a)/sizeof(a[0]);
    node *head = NULL;
    for(int i=0;i<n;i++){
        head = insert(head,a[i]);
    }
    cout<<"PREORDER : "<<endl;
    preorder(head);
    cout<<endl;
    iter_preorder2(head);
    cout<<endl<<"INORDER : "<<endl;
    inorder(head);
    cout<<endl;
    iter_inorder(head);
    cout<<endl<<"POSTORDER : "<<endl;
    postorder(head);
    cout<<endl;
    iter_postorder(head);
    cout<<endl;
    iter_postorder2(head);
    cout<<endl<<endl;
    level_order(head);
    return 0;
}