#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 1; i <= n; i++)
#define _rep(i, a, b) for (int i = a; i <= b; i++)
#define endl '\n'
const int maxn = 510;
int pre[maxn][maxn]; // 经计算int够用了
int n[maxn][maxn];
int row, col, a, b;
int get(int x1, int y1, int x2, int y2)
{
    return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
}
bool checkr(int top, int but, int m)
{
    int cnt = 0;
    int x = 0;
    _for(i, col)
    {
        x += get(top, i, but, i);
        if (x >= m)
        {
            cnt++;
            x = 0;
        } // 贪心法可以证明这样总会是最优的
    }
    return cnt >= b;
}

// 二分检验函数
bool check(int m)
{
    int blocks = 0;
    int sum = 1;
    _for(i, row)
    {
        if (checkr(sum, i, m))
        {
            blocks++;
            sum = i + 1;
        }
    }
    return blocks >= a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> row >> col >> a >> b;
    int tot = 0; // 巧克力豆总数
    _for(i, row) _for(j, col)
    {
        cin >> n[i][j];
        pre[i][j] = n[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        tot += n[i][j];
    }

    int l = 1, r = tot;
    int ans = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (check(m))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    cout << ans << endl;
    return 0;
}