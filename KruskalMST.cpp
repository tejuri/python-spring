#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct UnionFind {
    int *parent, *ranks, size;
};

UnionFind setup(UnionFind uf, int size){
    uf.parent = new int[size];
    uf.ranks = new int[size];
    for(int element = 0 ; element < size ; element++){
        uf.parent[element] = element;
        uf.ranks[element] = 0 ;
    }
    uf.size = size;
    return uf;
}

int find(UnionFind uf, int element){
        if(uf.parent[element] == element){
            return element;
        }
        else{
            return uf.parent[element] = find(uf, uf.parent[element]);
        }
}

bool connected(UnionFind uf, int x,int y){
    if(find(uf, x) == find(uf, y)){
        return true;
    }
    else{
        return false;
    }
}

void merge(UnionFind uf, int x,int y){
    x = find(uf, x);
    y = find(uf, y);
    if(x != y){
        if(uf.ranks[x] > uf.ranks[y]){
            uf.parent[y] = x;
        }
        else if(uf.ranks[x] < uf.ranks[y]){
            uf.parent[x] = y;
        }
        else{
            uf.parent[x] = y;
            uf.ranks[y] ++ ;
        }
        uf.size--;
    }
}

struct Edge {
    int src;
    int dest;
    int weight;
};

struct Node {
    int weight;
    int node;
};

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

Edge* edges;

void BFS(Graph g, int n){
    int k=0;
    queue<int> q;
    g.visited[n] = true;
    q.push(n);
    while(!q.empty()){
        n = q.front();
        q.pop();
        for (int i=0; i<g.n; ++i)
        {
            if(g.edges[n][i]){
                Edge edge;
                edge.src = n;
                edge.dest = i;
                edge.weight = g.edges[n][i];
                edges[k++] = edge;
                if(!g.visited[i])
                {
                    g.visited[i] = true;
                    q.push(i);
                }
        }
        }
    }
}

bool comparator(const Edge &a,const Edge &b){
    return a.weight < b.weight;
}

Edge* kruskalsAlgorithm(int n, int m){
    int k=0;
    UnionFind uf;
    uf = setup(uf, n);
    Edge* spanningTree = new Edge[n-1];
    sort(edges, edges + m, comparator);
    Edge first = edges[0];
    spanningTree[k++] = first;
    merge(uf, first.src,first.dest);
    for(int i=1;i<m;i++){
        if(!connected(uf, edges[i].src, edges[i].dest)){
            merge(uf, edges[i].src, edges[i].dest);
            spanningTree[k++] = edges[i];
        }
    }
    return spanningTree;
}

int main(){
    int n,n1,n2,w,m=0;
    cout<<"enter the number of nodes\n";
    cin>>n;
    Graph graph;
    graph = setup(graph, n);
    cout<<"Enter the source and destination respectively. To stop input type (-1, -1)\n";
    while(true) {
        cin>>n1>>n2>>w;
        if(n1<0 || n2<0)break;
        addEdge(graph, n1, n2,w);
        m+=2;
    }
    edges = new Edge[m];
    for(int i=0;i<graph.n;i++)
        if(!graph.visited[i])
            BFS(graph, i);
    Edge* spanningTree = kruskalsAlgorithm(graph.n, m);
    cout<<"Minimal Spanning Tree obtain through Kruskal's Alogrithm\n";
    cout<<"Edge \tWeight\n";
    for(int i=0;i<graph.n-1;i++){
        cout << spanningTree[i].src << " - " << spanningTree[i].dest << "\t" << spanningTree[i].weight << endl;
    }
}
