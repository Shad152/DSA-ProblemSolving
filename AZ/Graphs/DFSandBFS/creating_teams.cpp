#include<bits/stdc++.h>
using namespace std;

const int N=(int)(1e5)+10;

vector<int> adj[N];
int color[N];
int is_bipartite=1;
void DFS(int node, int parCol){
    color[node]=3-parCol;
    for(int neighbour:adj[node]){
        if(!color[neighbour]){
            DFS(neighbour,3-parCol);
        }
        else if(color[neighbour]==color[node]){
            is_bipartite=0;
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int node=1;node<=n;node++){
        if(color[node]==0){
            DFS(node,1);
        }
    }
    cout<<(is_bipartite?"YES":"NO");
}