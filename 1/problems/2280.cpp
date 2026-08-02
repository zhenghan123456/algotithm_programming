#include <bits/stdc++.h>
using namespace std;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
const int maxn = 1e4 + 10;
int mp[maxn][maxn], pre[maxn][maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    // 初始化地图
    _for(i, n)
    {
        int x, y, v;
        cin >> x >> y >> v;
        mp[x][y] += v;
    }

    // 初始化前缀和
}