#include<iostream>
using namespace std;

struct Graph {
    int n;
    bool *visited;
    int **edges;
};

Graph setup(Graph g, int n){
    g.n=n;
    g.visited = new bool[n];
    for(int i=0;i<n;i++){
        g.visited[i]=false;
    }
    g.edges = new int*[n];
    for(int i=0;i<n;i++){
        g.edges[i]=new int[n];
        for(int j=0;j<n;j++)
            g.edges[i][j]=0;
    }
    return g;
}

void addEdge(Graph g, int n1, int n2, int weight){
    g.edges[n1][n2]=weight;
    g.edges[n2][n1]=weight;
}

int minWeightKey(Graph g, int weights[], int n){
    int min=INT_MAX, index=0;
    for (int i = 0; i < g.n; ++i){
        if(!g.visited[i]&&weights[i]<min){
            min=weights[i];
            index = i;
        }
    }
    return index;
}

void printMST(int parent[], Graph g)
{
    cout<<"Edge \tWeight\n";
    for (int u = 1; u < g.n; u++){
        for (int k = 0; k <g.n; ++k){
            if(k==parent[u]&&g.edges[u][k]){
                cout<<parent[u]<<" - "<<u<<"\t"<<g.edges[u][k]<<endl;
            }
        }
    }
}

void primMST(Graph g)
{
    int parent[g.n];
    int weights[g.n];

    for (int i = 0; i < g.n; i++){
        weights[i] = INT_MAX;
        parent[i] = -1;
        g.visited[i] = false;
    }
    weights[0] = 0;
    for (int j = 0; j < g.n - 1; j++) {
        int u = minWeightKey(g, weights, j);
        g.visited[u] = true;
        for (int k = 0; k < g.n; ++k){
            if (!g.visited[k]&&g.edges[u][k] && g.edges[u][k]<weights[k]){
                parent[k] = u;
                weights[k]=g.edges[u][k];
            }
        }
    }
    printMST(parent, g);
}

int main(){
    int n,n1,n2,w;
    cout<<"enter the number of nodes\n";
    cin>>n;
    Graph graph;
    graph = setup(graph, n);
    while(true) {
    cout<<"Enter the source and destination respectively. To stop input type (-1, -1)\n";
        cin>>n1>>n2>>w;
        if(n1<0 || n2<0)break;
        addEdge(graph, n1, n2,w);
    }
    cout<<"Minimal Spanning Tree obtain through Prim's Alogrithm\n";
    primMST(graph);
}
