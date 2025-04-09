
#include <bits/stdc++.h>
using namespace std;
const int INF = (int)(2e9);
bool isValid(int r,int c, int N){
    if(r<0 || r>N || c<0 || c>N){
        return false;
    }
    return true;
}
int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{
    // Complete the function
    vector<vector<int>> directions = {{2,-1},{2,1},{-2,-1},{-2,1},{1,2},{1,-2},{-1,2},{-1,-2}}; 
    vector<vector<int> > dis(N+1,vector<int>(N+1,INF));
    queue<pair<int, int>> que;
    que.push({Sx, Sy});
    dis[Sx][Sy]=0;
    while (!que.empty())
    {
        pair<int,int> cur=que.front();
        que.pop();
        int x=cur.first,y=cur.second;
        if(x==Fx && y==Fy){
            return dis[Fx][Fy];
        }
        for(vector<int> dir:directions){
            int nx=x+dir[0];
            int ny=y+dir[1];
            if(isValid(nx,ny,N) && dis[nx][ny]==INF){
                dis[nx][ny]=dis[x][y]+1;
                que.push({nx,ny});
            }
        }
    }
    return -1;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;

    while (test_case--)
    {
        int N, Sx, Sy, Fx, Fy;
        cin >> N >> Sx >> Sy >> Fx >> Fy;

        cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
    }
}