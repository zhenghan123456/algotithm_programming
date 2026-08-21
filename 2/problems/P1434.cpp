#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
bool vis[105][105];
int h[105][105];
int dp[105][105];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int r, c;
int dfs(int x, int y)
{
    if (dp[x][y])
        return dp[x][y];
    int ans = 1;
    _for(i, 4)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < r && ny < c && h[nx][ny] < h[x][y])
        {
            ans = max(ans, dfs(nx, ny) + 1); // 记得+1
        }
    }
    return dp[x][y] = ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    int maxlen = 0;
    _for(i, r) _for(j, c) cin >> h[i][j];
    _for(i, r) _for(j, c) maxlen = max(dfs(i, j), maxlen);
    cout << maxlen << endl;
}