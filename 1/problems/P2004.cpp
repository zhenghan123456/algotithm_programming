#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

const int maxn = 1e3 + 10;
int a[maxn][maxn], pre[maxn][maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, c;
    cin >> n >> m >> c;
    _for(i, n)
    {
        _for(j, m)
        {
            cin >> a[i][j];
        }
    }
    pre[0][0] = a[0][0];
    _rep(i, 1, n)
    {
        pre[i][0] = a[i][0] + pre[i - 1][0];
    }
    _rep(i, 1, m)
    {
        pre[0][i] = a[0][i] + pre[0][i - 1];
    }
    _rep(i, 1, n)
    {
        _rep(j, 1, m)
        {
            pre[i][j] = a[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    int maxx = INT_MIN;
    int maxi = 0, maxj = 0;
    _for(i, n - c + 1)
    {
        _for(j, m - c + 1)
        {
            int val;
            if (i)
            {
                if (j)
                    val = pre[i + c - 1][j + c - 1] - pre[i - 1][j + c - 1] - pre[i + c - 1][j - 1] + pre[i - 1][j - 1];
                else
                    val = pre[i + c - 1][j + c - 1] - pre[i - 1][j + c - 1];
            }
            else
            {
                if (j)
                    val = pre[i + c - 1][j + c - 1] - pre[i + c - 1][j - 1];
                else
                    val = pre[i + c - 1][j + c - 1];
            }
            if (val > maxx)
            {
                maxx = val;
                maxi = i;
                maxj = j;
            }
        }
    }
    cout << maxi + 1 << ' ' << maxj + 1 << endl;
    return 0;
}