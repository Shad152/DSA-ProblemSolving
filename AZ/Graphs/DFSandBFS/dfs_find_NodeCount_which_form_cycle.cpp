#include<bits/stdc++.h>
using namespace std;
const int N=(int)(1e5)+10;
vector<vector<int> > adj;
vector<int> parents;
vector<int> count_nodes_in_cycle;
vector<int> col;

void DFS(int cur,int par){
    parents[cur]=par;
    col[cur]=2;
    for(int child:adj[cur]){
        if(col[child]==1){
            DFS(child,cur);
            count_nodes_in_cycle[cur]+=count_nodes_in_cycle[child];
        }
        else if(col[child]==2){
            //there is an back edge cycle found
            count_nodes_in_cycle[cur]++;
            count_nodes_in_cycle[parents[child]]--;
        }
    }
    // All neighbours of current node is explored so there won't be any back edge in future
    col[cur]=3;
}

int main(){
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    parents.assign(n+1,0);
    count_nodes_in_cycle.assign(n+1,0);
    col.assign(n+1,1);
    for (int  i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int node=1;node<=n;node++){
        if(col[node]==1){
            DFS(node,0);
        }
    }
    int total_nodes_count_in_cycle=0;
    for (int  node = 1; node <=n; node++)
    {
        total_nodes_count_in_cycle+=count_nodes_in_cycle[node];
    }
    cout<<total_nodes_count_in_cycle;
    
}
