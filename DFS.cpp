#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int n;
    bool *visited;
    list<int> *edges;
};

Graph setup(Graph g, int n){
    g.n=n;
    g.visited = new bool[n];
    g.edges = new list<int>[n];
    return g;
}

void addEdge(Graph g, int n1, int n2){
    g.edges[n1].push_back(n2);
    g.edges[n2].push_back(n1);
}

void DFS(Graph g, int n){
g.visited[n] = true;
cout<<n<<" ";
list<int>::iterator i;
for (i = g.edges[n].begin(); i != g.edges[n].end(); ++i)
    if (!g.visited[*i])
        DFS(g, *i);
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
            DFS(g, i);
}
