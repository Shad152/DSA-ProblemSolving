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
const int N = (int)(1e5 + 10);
vector<int> adj[N];
bool is_cycle=false;
stack<int> psf;
int vis[N];
void dfs(int node, int par){
    vis[node]=1;
    psf.push(node);
    for(int nb:adj[node]){
        if(!vis[nb]){
            dfs(nb,node);
            psf.pop();
        }
        else if(nb!=par){
            //cycle is found
            
        }
    }
}


void testCases() {
       int n,m;
       cin>>n>>m;
       for(int i=1;i<=m;i++){
         int a,b;
         adj[a].push_back(b);
         adj[b].push_back(a);
       }
}

int32_t main()
{
IOS;
#ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
#endif
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