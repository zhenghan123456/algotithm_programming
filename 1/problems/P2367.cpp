#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 10;
int a[maxn], d[maxn];
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    _for(i, n)
    {
        cin >> a[i];
    }
    // 初始化差分
    d[0] = a[0];
    _rep(i, 1, n)
    {
        d[i] = a[i] - a[i - 1];
    }
    _for(i, p)
    {
        int l, r, v;
        cin >> l >> r >> v;
        // 转为0_based
        l--;
        r--;
        d[l] += v;
        d[r + 1] -= v;
    }
    a[0] = d[0];
    _rep(i, 1, n) a[i] = d[i] += d[i - 1]; // 当然这里也可以对差分数组原地操作，不过这样语义更明确
    int minn = INT_MAX;
    // 求最小值
    _for(i, n) if (minn > a[i]) minn = a[i];

    cout << minn << endl;
}