#include <iostream>
using namespace std;

char mp[105][105];
bool vis[105][105];
int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// x,y 当前坐标
bool dfs(int x, int y)
{
    // 越界，碰到墙，访问过 → 走不通
    if (x < 1 || x > n || y < 1 || y > m || mp[x][y] == '#' || vis[x][y])
        return false;

    // 到达终点
    if (x == n && y == m)
        return true;

    vis[x][y] = true;

    // 四个方向尝试
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (dfs(nx, ny))
            return true;
    }
    // 四个方向全部走不通
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> mp[i] + 1;
    if (dfs(1, 1))
        cout << "可以到达终点";
    else
        cout << "无路可走";
    return 0;
}
