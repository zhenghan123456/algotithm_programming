#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

const int maxn = 1000001;
ll sum[maxn];
ll n, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    if (k >= n - 1)
    {
        cout << endl;
        return 0;
    }

    // 构建前缀和 sum[1]~sum[n-1]
    _rep(i, 1, n)
    {
        ll x;
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }

    ll cnt = sum[k];
    // 滑动窗口枚举所有长度k的区间
    _rep(i, 2, n - k + 1)
    {
        int r = i + k - 1;
        cnt = max(cnt, sum[r] - sum[i - 1]);
    }

    cout << sum[n - 1] - cnt << endl;
    return 0;
}