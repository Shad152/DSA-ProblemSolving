#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> vis;
vector<string> grid;
vector<vector<int>> dis;
bool isValid(int r, int c)
{
    if (r < 0 || r >= n || c < 0 || c >= m)
    {
        return false;
    }
    return true;
}
int BFS()
{
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    queue<pair<int, int>> q;
    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                vis[i][j] = 1;
                dis[i][j] = 0;
                dq.push_back({i, j});
            }
            else if (grid[i][j] == 'M')
            {
                vis[i][j] = 2;
                dis[i][j] = 0;
                dq.push_front({i, j});
            }
        }
    }
    while (!dq.empty())
    {
        q.push(dq.front());
        dq.pop_front();
    }
    while (!q.empty())
    {
        int qSize = q.size();
        while (qSize--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if ((x == 0 || y == 0 || x == n - 1 || y == m - 1) && vis[x][y] == 1)
            {
                return dis[x][y];
            }
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (isValid(nx, ny) && !vis[nx][ny] && grid[nx][ny] != '#')
                {
                    vis[nx][ny] = vis[x][y];
                    dis[nx][ny] = 1 + dis[x][y];
                    if (vis[nx][ny] == 1)
                    {
                        dq.push_back({nx, ny});
                    }
                    else
                    {
                        dq.push_front({nx, ny});
                    }
                }
            }
        }
        while (!dq.empty())
        {
            q.push(dq.front());
            dq.pop_front();
        }
    }
    return -1;
}
int main()
{

    cin >> n >> m;
    vis.assign(n, vector<int>(m, 0));
    dis.assign(n, vector<int>(m, -1));
    grid.resize(n);
    for (int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        grid[i] = row;
    }
    int res = BFS();
    if (res == -1)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES" << '\n';
        cout << res;
    }
}