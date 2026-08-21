#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
const int maxn = 1010;
bool a[maxn][maxn];
bool vis[maxn][maxn];
int ans[maxn][maxn];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;
#define pb push_back
struct point
{
    int x, y;
};
struct node
{
    point p;
    vector<node *> child;
} nodes[maxn][maxn];
void dfs(node &p, bool b, node &start)
{
    if (vis[p.p.x][p.p.y])
        return;
    if (!(a[p.p.x][p.p.y] ^ b))
        return;
    vis[p.p.x][p.p.y] = 1;
    start.child.pb(&p); // 添加节点
    _for(i, 4)
    {
        int x = p.p.x + dx[i];
        int y = p.p.y + dy[i];
        if (x >= 0 && x < n && y >= 0 && y < n)
            dfs(nodes[x][y], a[p.p.x][p.p.y], start);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> n >> m;
    _for(i, n) _for(j, n)
    {
        nodes[i][j].p = {i, j};
        char c;
        cin >> c;
        a[i][j] = c - '0';
    }
    _for(i, n) _for(j, n) dfs(nodes[i][j], !a[i][j], nodes[i][j]);
    _for(i, n) _for(j, n)
    {
        int sz = nodes[i][j].child.size();
        for (auto k : nodes[i][j].child)
        {
            ans[k->p.x][k->p.y] = sz;
        }
    }
    while (m--)
    {
        int i, j;
        cin >> i >> j;
        cout << ans[i - 1][j - 1] << endl;
    }
}