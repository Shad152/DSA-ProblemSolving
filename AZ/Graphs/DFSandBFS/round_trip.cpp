#include<bits/stdc++.h>
using namespace std;

const int N=(int)(2e5)+10;

int col[N];
vector<int> adj[N];
int is_cycle=0;
void DFS(int node, int par){
    col[node]=1;
    for(int neib:adj[node]){
        if(!col[neib]){
            DFS(neib,node);
        }
        else if(neib!=par && col[neib]==1){
            //back edge is present so cycle is found
            is_cycle=1;
        }
    }
    col[node]=2;
}
int main(){
    int n,m;
    cin>>n>>m;
    for (int  i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int node=1;node<=n;node++){
        if(!col[node]){
            DFS(node,0);
        }
    }
    cout<<(is_cycle?"YES":"NO");
}