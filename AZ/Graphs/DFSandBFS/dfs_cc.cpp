#include <bits/stdc++.h>
using namespace std;
using ll=long long ;
#define all(x) (x).begin(),(x).end()
#define rall(v) v.rbegin(),v.rend()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (int)(x.size())
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void ZZ(const char* name, Arg1&& arg1){std::cerr << name << '=' << arg1 << endl;}
template <typename Arg1, typename... Args>void ZZ(const char* names, Arg1&& arg1, Args&&... args)

{
const char* comma = strchr(names + 1, ',');
std::cerr.write(names, comma - names) << '=' << arg1;
ZZ(comma, args...);
}

const int mod=(int)(1e9)+7;
const int inf=(int)(2e9);
const int nax=(int)(1e3+10);
vector<int> adj[nax];
vector<int> cc_nodes;
int dfs(int node,vector<bool> &vis){
    vis[node]=true;
    cc_nodes.push_back(node);
    int counter=1;
    for(int neib:adj[node]){
        if(!vis[neib]){
            counter+=dfs(neib,vis);
        }
    }
    return counter;
}
void testCases() {
    int n,m;
    cin>>n>>m;
    vector<bool> vis(n+1,false);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cc_counts=0;
    for (int  node = 1; node <=n; node++)
    {
        int total_nodes_cc;
        if(!vis[node]){
            total_nodes_cc=dfs(node, vis);
            cout << "total_nodes_in_cur_cc:" << total_nodes_cc << '\n';
            cout << "actual_nodes_in_cc: ";
            for (int x : cc_nodes)
            {
                cout << x << "->";
            }
            cout << '\n';
        }
        cc_nodes.clear();


    }
    
}

int32_t main()
{
IOS;
// #ifndef ONLINE_JUDGE
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
// #endif
// comment for single Test Case
int t=1;
//  cin>>t;
 for(int T=1;T<=t;T++)
 {

   // cout << "Case #" << T << ": ";
   testCases();
}

return 0;
}