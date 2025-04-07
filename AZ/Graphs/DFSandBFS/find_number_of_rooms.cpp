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
int n, m;
vector<string> grid;
vector<vector<int> > vis;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
bool isValid(int r, int c){
    if (r >= n || c >= m || r < 0 || c < 0)
    {
        return false;
    }
    return true;
}
void dfs(int r, int c){
    
    vis[r][c]=1;
    for(int k=0;k<4;k++){
         int nr=r+dx[k];
         int nc=c+dy[k];
         if(isValid(nr,nc) && !vis[nr][nc] && grid[nr][nc]=='.'){
             dfs(nr,nc);
         }
    }

}
void testCases() {
       
       cin>>n>>m;
       grid.resize(n);
       vis.resize(n,vector<int>(m,0));
       for (int  i = 0; i < n; i++)
       {
            cin>>grid[i];  
       }
       int no_comp=0;
       for (int  i = 0; i < n; i++)
       {
         for (int  j = 0; j < m; j++)
         {
            if(grid[i][j]=='.' && !vis[i][j]){
                no_comp++;
                dfs(i,j);
            }
         }
         
       }
       cout<<no_comp;
       

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