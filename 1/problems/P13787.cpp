#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 1; i <= n; i++)
#define _rep(i, a, b) for (int i = a; i <= b; i++)
#define endl '\n'
const int maxn = 5e3 + 10;
int a[maxn][maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1]++;
        a[x2 + 1][y1]--;
        a[x1][y2 + 1]--;
        a[x2 + 1][y2 + 1]++;
    }
    // 二维差分还原
    _for(i, n)
    {
        _for(j, n)
        {
            a[i][j] += a[i - 1][j];
        }
    }
    _for(i, n)
    {
        _for(j, n)
        {
            a[i][j] += a[i][j - 1];
        }
    }
    ll sum = 0;
    _for(i, n)
    {
        _for(j, n)
        {
            sum += (i + j) ^ a[i][j];
        }
    }
    cout << sum << endl;
}