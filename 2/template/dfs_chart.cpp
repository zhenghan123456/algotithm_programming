#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

const int maxn = 105;
bool g[maxn][maxn]; // 邻接矩阵
bool vis[maxn];
int n, m;

void dfs(int u)
{
    cout << u << " ";
    vis[u] = true;
    _rep(v, 1, n + 1)
    {
        if (g[u][v] && !vis[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    _for(i, m)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = true;
    }
    dfs(1);
    return 0;
}