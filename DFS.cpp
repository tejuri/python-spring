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

void addEdge(Graph g, int n1, int n2){
    g.edges[n1][n2]=1;
}

void DFS(Graph g, int n){
g.visited[n] = true;
cout<<n<<" ";
for (int i = 0; i<g.n; ++i){
    if (!g.visited[i] && g.edges[n][i])
        DFS(g, i);
}
}

int main(){
    int n,n1,n2;
    cout<<"enter the number of nodes\n";
    cin>>n;
    Graph g;
    g = setup(g, n);
    while(true) {
    cout<<"Enter the source and destination respectively. To stop input type (-1, -1)\n";
        cin>>n1>>n2;
        if(n1<0 || n2<0)break;
        addEdge(g, n1, n2);
    }
    cout<<endl;
    for(int i=0;i<g.n;i++)
        if(!g.visited[i])
            DFS(g, i);
}
