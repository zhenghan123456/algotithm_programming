#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int sx, sy, fx, fy;
int n, m, t;
bool matrix[5][5];
bool vis[5][5];
int dx[] = {1, 0, -1, 0}; // 方向数组
int dy[] = {0, 1, 0, -1};
int dfs(int x, int y)
{
    if (x == fx && y == fy)
        return 1; // 到终点了
    int cnt = 0;
    _for(i, 4)
    {
        // 越界检查
        if ((x + dx[i] < 0) || (y + dy[i] < 0))
            continue;
        if ((x + dx[i] >= n) || (y + dy[i] >= m))
            continue;
        if (!matrix[x + dx[i]][y + dy[i]] && (!vis[x + dx[i]][y + dy[i]]))
        {
            vis[x + dx[i]][y + dy[i]] = true; // 添加标记
            cnt += dfs(x + dx[i], y + dy[i]);
            vis[x + dx[i]][y + dy[i]] = false; // 撤销标记
        }
    }
    return cnt; // 既然没有到达终点的可能（已经排除了）那么遇到死胡同直接返回0即可无需判断
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    sx--;
    sy--;
    fx--;
    fy--;
    vis[sx][sy] = true; // 先给起点打上标记
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        matrix[x][y] = true;
    }
    cout << dfs(sx, sy) << endl;
}