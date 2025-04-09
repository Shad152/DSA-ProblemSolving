#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=(int)(1e9);
const int N=(int)(2e5)+10;
int comp_size[N];
bool isValid(int x,int y, int m, int n){
    if(x<0 || x>=m || y<0 || y>=n){
        return false;
    }
    return true;
}
void BFS(int r,int c,vector<vector<int>> & grid,int comp ){
    int m=grid.size();
    int n=grid[0].size();
    int directions[4][2] ={{0,1},{0,-1},{1,0},{-1,0}};
    queue<pair<int,int> > que;
    grid[r][c]=comp;
    que.push({r,c});
    int cur_comp_size=1;
    while (!que.empty())
    {
        pair<int,int> cur=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            int nx=cur.first+directions[i][0];
            int ny=cur.second+directions[i][1];
            if(isValid(nx,ny,m,n) && grid[nx][ny]==0){
                cur_comp_size++;
                grid[nx][ny]=comp;
                que.push({nx,ny});
            }
        }
    }
    comp_size[comp]=cur_comp_size;
    
}
void testCases(){
   int n,m;
   cin>>n>>m;
   vector<vector<int> > grid(n,vector<int>(m,0));
    for (int  i = 0; i < n; i++)
    {
        for (int  j = 0; j < m; j++)
        {
            cin>>grid[i][j];
        }
        
    }
    int comp=2;
    for (int  r = 0; r < n; r++)
    {
       for (int  c = 0; c < m; c++)
       {
            if(grid[r][c]==0){
                BFS(r,c,grid,comp);
                comp++;
            }
       }
       
    }
    for (int  r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            if(grid[r][c]>1 && comp_size[grid[r][c]]>1){
                cout << comp_size[grid[r][c]]<<" ";
            }else{
                cout<<(grid[r][c]!=1?0:1)<<" ";
            }
        }
        cout<<'\n';
        
    }
    

}

int main(){
    int T;
    cin>>T;
    for (int  i = 0; i < T; i++)
    {
        testCases();
    }
    
}
