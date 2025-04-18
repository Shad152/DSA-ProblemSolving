#include<bits/stdc++.h>
using namespace std;
const int INF=(int)(1e9);
struct Pair {
    int r;
    int c;
     Pair(int r,int c){
        this->r=r;
        this->c=c;
    }
};
bool isValid(int r,int c,int N, int M){
    if(r<0 || r>=N || c<0 || c>=M){
        return false;
    }
    return true;
}
void BFS(vector<vector<int>> &grid,vector<vector<int>> &dis){
    int dx[]={0,0,-1,1};
    int dy[]={-1,1,0,0};
    queue<Pair> q;
    int n=grid.size();
    int m=grid[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push(Pair(i,j));
                dis[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        Pair cur=q.front();
        q.pop();
        int x=cur.r;
        int y=cur.c;
        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(isValid(nx,ny,n,m) && grid[nx][ny]==1 && dis[nx][ny]==INF){
                q.push(Pair(nx,ny));
                dis[nx][ny]=1+dis[x][y];
            }
        }
    }
}

int main(){
    int N,M;
    cin>>N>>M;
    vector<vector<int>> grid(N,vector<int>(M));
    vector<vector<int>> dis(N,vector<int>(M,INF));
    for (int  i = 0; i < N; i++){    
        for (int  j = 0; j < M; j++){
            cin>>grid[i][j];
        }
    }
    BFS(grid,dis);
    int timeTaken=0;
    for(int i=0;i<N;i++){
        bool found=false;
        for(int j=0;j<M;j++){
            if(grid[i][j]==1 && dis[i][j]==INF){
                found=true;
                break;
            }else if(grid[i][j]!=0 && dis[i][j]){
                timeTaken=max(timeTaken,dis[i][j]);
            }
        }
        if(found){
            timeTaken=-1;
            break;
        }
    }
    cout<<timeTaken;
}