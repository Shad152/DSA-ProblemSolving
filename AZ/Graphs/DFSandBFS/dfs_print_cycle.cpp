#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=(int)2e9;
const int N=(int)(1e5)+10;
int vis[N];
vector<vector<int> > cycles;
void DFS(int src,vector<int> &path,vector<vector<int> > &adj){
    vis[src]=1;
    path.push_back(src);
    for(int neib:adj[src]){
        if(!vis[neib]){
            DFS(neib,path,adj);
        }
        //Found back edge means cycle is present here
        else if(vis[neib]==1){
            cycles.push_back(path);
        }
    }
    vis[src]=2;
    path.pop_back();
}
int main(){
   int n,m;
   cin>>n>>m;
   vector<vector<int> > adj(n+1);
   for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
   }
   vector<int> path;
   DFS(1,path,adj);
   int cycle_cnt=1;
   for(vector<int> cycle:cycles){
     cout<<"Found cycle number: "<<cycle_cnt<<'\n';
        for(int node:cycle){
            cout<<node<<" ->";
        }
        cout<<'\n';
        cycle_cnt++;
   }

}
