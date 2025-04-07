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
const int N = (int)(1e5)+10;
vector<int> adj[N];
int markNode[N];
void dfs(int node, int comp){
    markNode[node]=comp;
    for(int child:adj[node]){
        if(!markNode[child]){
            dfs(child,comp);
        }
    }
}

void testCases() {
      int n,m;
      cin>>n>>m;
      for (int  i = 0; i < m; i++)
      {
         int u,v;
         cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
      }
      int component=0;
      memset(markNode,0,sizeof(markNode));
      for(int x=1;x<=n;x++){
            
            if(!markNode[x]){
                component++;
                dfs(x,component);
            }
      }
      vector<ll> comp_size(component+2,0);
      for(int node=1;node<=n;node++){
         comp_size[markNode[node]]++;
      }
      ll ans=0;
      ll suf_sum=comp_size[component];
      for(int x=component-1;x>=1;x--){
            ans+=comp_size[x]*suf_sum;
            suf_sum+=comp_size[x];
      }
      cout<<ans;
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