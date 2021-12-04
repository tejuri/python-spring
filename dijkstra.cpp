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

int minWeightKey(Graph g, int weights[]){
    int min=INT_MAX, index=0;
    for (int i = 0; i < g.n; ++i){
        if(!g.visited[i]&&weights[i]<min){
            min=weights[i];
            index = i;
        }
    }
    return index;
}

void printOverallWeights(int weights[], int n)
{
    cout<<"Vertex \tDistance from Source\n";
    for (int u = 0; u < n; u++){
        cout<<u<<"\t"<<weights[u]<<endl;
    }
}

void singleSourceShortestPath(Graph g)
{
    int weights[g.n];

    for (int i = 0; i < g.n; i++){
        weights[i] = INT_MAX;
        g.visited[i] = false;
    }
    weights[0] = 0;
    for (int j = 0; j < g.n - 1; j++) {
        int u = minWeightKey(g, weights);
        g.visited[u] = true;
        for (int k = 0; k < g.n; ++k){
            if (!g.visited[k]&&g.edges[u][k] && weights[u] != INT_MAX && (weights[u] + g.edges[u][k]<weights[k])){
                weights[k]=weights[u] + g.edges[u][k];
            }
        }
    }
    printOverallWeights(weights, g.n);
}

int main(){
    int n,n1,n2,w;
    cout<<"enter the number of nodes\n";
    cin>>n;
    Graph graph;
    graph = setup(graph, n);
    cout<<"Enter the source and destination respectively. To stop input type (-1, -1)\n";
    while(true) {
        cin>>n1>>n2>>w;
        if(n1<0 || n2<0)break;
        addEdge(graph, n1, n2,w);
    }
    singleSourceShortestPath(graph);
}
