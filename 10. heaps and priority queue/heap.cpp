#include<iostream>
#include<vector>
using namespace std;
class Heap{
    vector<int> v;
    bool isMinHeap;

    bool compare(int a,int b){
        if(isMinHeap==true){
            return a<b;
        }
        else
        {
            return a>b;
        }
    }

    void heapify(int i){
        int minIndex = i;
        if(2*i < v.size() && compare(v[2*i],v[i])){
            minIndex = 2*i;
        }
        if(2*i+1 <v.size() && compare(v[2*i+1],v[minIndex])){
            minIndex = 2*i+1;
        }

        if(minIndex!=i){
            swap(v[i],v[minIndex]);
            heapify(minIndex);
        }
    }
public:

    Heap(bool type = true){
        isMinHeap = type;
        v.push_back(-1);
    }

    void push(int data){
        v.push_back(data);
        int index = v.size()-1;
        int parent = index/2;
        while(index>1 && compare(v[index],v[parent])){
            swap(v[parent],v[index]);
            index = parent;
            parent = index/2;
        }
    }
    bool empty(){
        return v.size()==1;
    }

    int top(){
        if(!empty())
            return v[1];
        return -1;
    }

    void pop(){
        swap(v[1],v.back());
        v.pop_back();

        heapify(1);
    } 
    void show(){
        for(int x:v){
            cout<<x<<" ";
        }
        cout<<endl;
    }   
};
int main(){
    Heap h(false);
    h.push(29);
    h.push(2);
    h.push(4);
    h.push(3);
    h.push(9);
    h.push(7);
    h.show();
    while(!h.empty()){
        cout<<h.top()<<endl;
        h.pop();
    }
    return 0;
}