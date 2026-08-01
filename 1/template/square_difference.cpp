#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int a[maxn][maxn], diff[maxn][maxn];
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }
    // 二维差分预处理
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            diff[i][j] = a[i][j];
            if (i)
                diff[i][j] -= a[i - 1][j];
            if (j)
                diff[i][j] -= a[i][j - 1];
            if (i && j)
                diff[i][j] += a[i - 1][j - 1];
        }
    }

    // 二维差分查询
    while (q--)
    {
        int x1, y1, x2, y2, v;
        cin >> x1 >> y1 >> x2 >> y2 >> v;
        diff[x1][y1] += v;
        diff[x1][y2 + 1] -= v;
        diff[x2 + 1][y1] -= v;
        diff[x2 + 1][y2 + 1] += v;
    }

    // 还原差分
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            diff[i][j] += diff[i - 1][j];
        }
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            diff[j][i] += diff[j][i - 1]
        }
    }

    // 输出结果
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << diff[i][j] << " ";
        }
        cout << "\n";
    }
}