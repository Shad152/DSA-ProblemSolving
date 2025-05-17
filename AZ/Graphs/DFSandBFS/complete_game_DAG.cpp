#include<bits/stdc++.h>
using namespace std;
const int N=(int)(2e5)+10;
const int MOD=(int)(1e9)+7;
vector<int> adj[N];
int cache[N];
int dfs(int node){
   if(cache[node]!=-1){
     return cache[node];
   }
   int ways=0;
   for(int neigh:adj[node]){
      ways+=dfs(neigh);
      if(ways>=MOD) ways-=MOD;
   }
   return cache[node]=ways;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    memset(cache,-1,sizeof(cache));
    cache[n]=1;
    cout<<dfs(1);
    return 0;
}