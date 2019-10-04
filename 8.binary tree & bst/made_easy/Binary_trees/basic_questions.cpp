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
node *insert(node *h, int d)
{
    if (h == NULL)
    {
        h = new node(d);
        return h;
    }
    if (d <= h->data)
    {
        h->left = insert(h->left, d);
    }
    else
    {
        h->right = insert(h->right, d);
    }
    return h;
}
//find the max in a binary tree
int problem1(node *root){
    if(root==NULL){
        return INT_MIN;
    }
    int max1 = problem1(root->left);
    int max2 = problem1(root->right);

    return max(root->data,max(max1,max2));
}
//to find the deepest node in a tree
node *problem12(node *root){
    if(!root){
        return NULL;
    }
    node *f;
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        f = q.front();q.pop();
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
    return f;
}
int main(){
    int a[] = {3, 5, 2, 7, 2, 0, 4, 1, 3};
    int n = sizeof(a) / sizeof(a[0]);
    node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        head = insert(head, a[i]);
    }
    cout<<problem1(head)<<endl;
    cout<<problem12(head)->data<<endl;
    return 0;
}