#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> color;
int is_cycle;
void DFS(int node, int par){
    color[node]=1;
    for(int neighbour:adj[node]){
        if(!color[neighbour]){
            DFS(neighbour,node);
        }
        else if(neighbour!=par && color[neighbour]==1){
            //back edge that means cycle is found
            is_cycle=1;
        }
    }
    //Once all neighbour are explored completely there won't be any back edge to this node
    // So marking it as 3
    color[node]=2;
}
int main(){
    int T;
    cin>>T;
    for(int _=1;_<=T;_++){
        is_cycle = 0;
        int n,m;
        cin>>n>>m;
        adj.resize(n+1);
        color.assign(n+1, 0);
        map<pair<int,int>,int> edge_count;
        for (int  i = 0; i < m; i++)
        {
            int u,v;
            cin>>u>>v;
            if(u==v) continue;
            edge_count[make_pair(u,v)]++;
            if(edge_count[make_pair(u,v)]>1){
                continue;
            }
            adj[u].push_back(v);
        }
        for(int node=1;node<=n;node++){
            if(color[node]==0){
                DFS(node,0);
            }
        }
        cout<<(is_cycle?"Yes":"No")<<'\n';
    }
}