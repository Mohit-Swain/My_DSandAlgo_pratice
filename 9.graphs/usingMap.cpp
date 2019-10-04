#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<climits>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>> adjList;
public:
    //no constructor needed here 

    void addEdge(T u,T v,bool bidir = true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }

    void print(){
        for(auto i : adjList){
            cout<<i.first<<"->";
            for(auto entry : i.second){
                cout<<entry<<",";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void sssp(T src){
        queue<T> q;
        map<T,int> dist;
        map<T,T> parent;

        for(auto vert : adjList){
            dist[vert.first] = INT_MAX;
        }

        q.push(src);
        parent[src] = src;
        dist[src]=0;

        while(!q.empty()){
            T node = q.front();
            cout<<node<<" ";
            q.pop();

            for(auto neighbour : adjList[node]){
                if(dist[neighbour]==INT_MAX){
                    dist[neighbour] = dist[node] + 1;
                    q.push(neighbour);
                    parent[neighbour] = node;
                }
            }
        }

        for(auto it : adjList){
            T node = it.first;
            cout<<"Dist of "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
        }

        cout<<endl; 
        for(auto i : parent){
            cout<<"Parents of "<<i.first<<" are "<<i.second<<endl;
        }
    }

    void dfsHelper(T node,map<T,bool> &visited){
        // first print node then search
        visited[node]= true;
        cout<<node<<" ";

        for(T neighbour : adjList[node]){
            if(!visited[neighbour]){
                dfsHelper(neighbour,visited);
            }
        }
    }
    void dfs(T src){
        map<T,bool> visited;
        int component = 0;
        for(auto i : adjList){
            T node = i.first;
            if(!visited[node]){
                dfsHelper(node,visited);
                component++;
            }
        }

        cout<<endl<<"This graph has "<<component<<" component";
    }
};
int main(){
    Graph<int> g;
    g.addEdge(1,0);
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(4,3);
    g.addEdge(3,5);

    g.print();
    
    g.dfs(0);
    return 0;
}