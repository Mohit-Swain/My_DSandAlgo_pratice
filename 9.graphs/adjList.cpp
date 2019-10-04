#include<iostream>
#include<list>
using namespace std;

class Graph{
    list<int> *l;
    int V;
public:
    Graph(int v=4){
        V = v;
        l = new list<int>[v];
    }

    void addEdge(int u,int v,bool bidir=true){
        l[u].push_back(v);
        if(bidir){
            l[v].push_back(u);
        }
    }

    void print(){
        for(int i=0;i<V;i++){
            cout<<i<<"->";
            for(int vertex : l[i]){
                cout<<vertex<<",";
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,0);

    g.print();
    return 0;
}