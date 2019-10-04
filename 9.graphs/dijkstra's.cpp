#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
class Graph{
    int adjMat[100][100];
    bool *visited;
    int *dist;
    int n;
public:
    Graph(int d= 4){
        n = d;
        visited = new bool[n];
        dist = new int[n];
        memset(visited,false,sizeof(visited));
        memset(dist,INT_MAX,sizeof(dist));
        /* adjMat = new int*[n];
        for(int i=0;i<n;i++){
            adjMat[i] = new int[n];
        } */
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adjMat[i][j] = INT_MAX;
            }
        }
    }
    void print(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<adjMat[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
    }
    void addEdge(int s,int e,int d,bool bidir= true){

        adjMat[s][e] = d;
        if(bidir){
            adjMat[e][s]=d;
        } 
    }

    void dijkstra(int src){
        dist[src] = 0;
        int cd =0;
        while(1)
        {
            visited[src] = true;

            for(int i=0;i<n;i++){
                 if(adjMat[src][i]!= INT_MAX){
                     dist[i]= min(dist[i],cd + adjMat[src][i]);
                }
            }

            int m =-1,sd=INT_MAX;
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    if(dist[i]<sd){
                        m = i;
                        sd = dist[i];
                    }
                }
            }
            if(m == -1){
                break;
            }

            src = m;
            cd = dist[m];
        }

        for (int i = 0; i < n; i++)
        {
            cout << dist[i] << " ";
        }
    }
    
};

int main(){
    Graph g(5);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 8);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 4);
    g.addEdge(2, 4, 9);

    g.dijkstra(0);
    return 0;
}