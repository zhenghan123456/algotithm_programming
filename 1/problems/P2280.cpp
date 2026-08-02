#include <bits/stdc++.h>
using namespace std;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
const int maxn = 1e4 + 10;
const int maxx = 5e3 + 10;
int mp[maxx][maxx], pre[maxx][maxx];
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
        x++;
        y++;
        mp[x][y] += v;
    }

    // 初始化前缀和
    _rep(i, 1, maxx)
    {
        _rep(j, 1, maxx)
        {
            pre[i][j] = mp[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }

    int maxv = INT_MIN; // 最小值

    // 求解
    _rep(i, 1, maxx - m)
    {
        _rep(j, 1, maxx - m)
        {
            int i2 = i + m;
            int j2 = j + m;
            int sum = pre[i2][j2] - pre[i - 1][j2] - pre[i2][j - 1] + pre[i - 1][j - 1];
            if (sum > maxv)
                maxv = sum;
        }
    }

    cout << maxv << endl;
}
