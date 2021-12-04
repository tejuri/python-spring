#include<iostream>
using namespace std;

void floydWarshall(int **graph, int n){
    for (int k=0; k<n; ++k){
        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                int sum = graph[i][k]==INT_MAX || graph[k][j]==INT_MAX ? INT_MAX : graph[i][k] + graph[k][j];
                graph[i][j] = min (graph[i][j], sum);
            }
        }
    }
}

int main(){
    int **graph;
    int n,src,des,weight;
    cin >> n;
    graph = new int*[n];
    for(int i=0;i<n;i++){
        graph[i] = new int[n];
        for(int j=0;j<n;j++){
                if(i==j)
        graph[i][j] = 0;
        else graph[i][j] = INT_MAX;
        }
    }
    while(1){
        cin >> src >> des >> weight;
        if(src==-1 &&des==-1)break;
        graph[src][des] = weight;
    }
    floydWarshall(graph, n);
    cout<<"shortest distances between every pair of vertices\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j] == INT_MAX)cout<<"INT_MAX ";
            else
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
