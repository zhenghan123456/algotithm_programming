#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int a[maxn][maxn], pre[maxn][maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    // 构建二维前缀和 0-based
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pre[i][j] = a[i][j];
            if (i > 0)
                pre[i][j] += pre[i - 1][j];
            if (j > 0)
                pre[i][j] += pre[i][j - 1];
            if (i > 0 && j > 0)
                pre[i][j] -= pre[i - 1][j - 1];
        }
    }
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // 将题目1-based坐标转为代码0-based
        x1--, y1--, x2--, y2--;
        int ans = pre[x2][y2];
        if (x1 > 0)
            ans -= pre[x1 - 1][y2];
        if (y1 > 0)
            ans -= pre[x2][y1 - 1];
        if (x1 > 0 && y1 > 0)
            ans += pre[x1 - 1][y1 - 1];
        cout << ans << '\n';
    }
    return 0;
}
