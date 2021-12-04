#include<iostream>
#include<queue>
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

void BFS(Graph g, int n){
    queue<int> q;
    g.visited[n] = true;
    q.push(n);
    while(!q.empty()){
        n = q.front();
        cout<<n<<" ";
        q.pop();
        for (int i=0; i<g.n; ++i)
        {
            if(!g.visited[i] &&g.edges[n][i])
            {
                g.visited[i] = true;
                q.push(i);
            }
        }
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
    for(int i=0;i<g.n;i++)
        if(!g.visited[i])
            BFS(g, i);
}
