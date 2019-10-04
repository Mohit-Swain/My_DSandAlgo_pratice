//Tree is a graph without a cycle
//Implementing Graphs : 1. Edge List 2. Adjacency Matrix 3. Adjacency List

#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<queue>
using namespace std;

//Implementation using array of list
/* 
class Graph{
    int V;
    list<int> *lis;
public:
    Graph(int v=4){
        V = v;
        lis = new list<int>[V];
    }

    void addEdge(int u,int v,bool bidir = true){
        if(u>= V || v>=V){
            return;
        } 

        lis[u].push_back(v);

        if(bidir){
            lis[v].push_back(u);
        }
    }

    void printAdjList(){
        for(int vertex = 0 ;vertex < V ; vertex++){
            cout<<vertex<<" -> ";
            for(int neighbours : lis[vertex]){
                cout<<neighbours<<", ";
            }
            cout<<endl;
        }
    }
};
*/

//Implementation using HashMap
//Its a generic graph
template<typename T>
class Graph{
    // int V; NOT REQUIRED HERE !!
    map<T,list<T> > adjList;
public:
    Graph(){
        // NO constructor required
    }

    void addEdge(T u,T v,bool bidir = true){
        adjList[u].push_back(v);

        if(bidir){
            adjList[v].push_back(u);
        }
    }

    void printAdjList(){
        for(pair<T,list<T> > value : adjList){
            cout<<value.first<<" -> ";
            for(T neighbours : value.second){
                cout<<neighbours<<", ";
            }
            cout<<endl;
        }
    }

    void bfs(T s){
        map<T,bool> visited;
        map<T,int> dist;
        queue<T> q;

        q.push(s);
        visited[s] = true;
        dist[s] = 0;
        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node<<", ";

            for(T neighbours : adjList[node]){
                if(!visited[neighbours]){
                    q.push(neighbours);
                    dist[neighbours] = dist[node] + 1;
                    visited[neighbours] = true;
                }
            }
        }
        cout<<endl<<endl;
        for(auto d : dist){
            cout<<d.first<<" -> "<<d.second<<endl;
        }
    }
    void dfsHelper(int src,map<T,bool> &visited){
        visited[src]=true;
        for(T neighbours : adjList[src]){
            if(!visited[neighbours]){
                dfsHelper(neighbours,visited);
            }
        }
        cout<<src<<" ";
    }
    void dfs(int src){
        map<T,bool> visited;
        dfsHelper(src,visited);
    }

};

int main(){
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);

    g.printAdjList();

    g.bfs(0);

    cout<<endl;

    g.dfs(0);
    return 0;
}