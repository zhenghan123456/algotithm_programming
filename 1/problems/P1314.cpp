#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

const int MAXN = 200005;
int n, m;
ll sum;
int w[MAXN], v[MAXN];
int lft[MAXN], rt[MAXN];
ll cnt[MAXN], sumv[MAXN];

// 给定W，计算总Y
ll calc(int standard)
{
    memset(cnt, 0, sizeof cnt);
    memset(sumv, 0, sizeof sumv);
    _rep(i, 1, n + 1)
    {
        if (w[i] >= standard)
        {
            cnt[i] = cnt[i - 1] + 1;
            sumv[i] = sumv[i - 1] + v[i];
        }
        else
        {
            cnt[i] = cnt[i - 1];
            sumv[i] = sumv[i - 1];
        }
    }
    ll Y = 0;
    _for(j, m)
    {
        int l = lft[j], r = rt[j];
        ll c = cnt[r] - cnt[l - 1];
        ll sv = sumv[r] - sumv[l - 1];
        Y += c * sv;
    }
    return Y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> sum;
    _rep(i, 1, n + 1) cin >> w[i] >> v[i];
    _for(j, m) cin >> lft[j] >> rt[j];

    int l = 0, r = 1000000;
    ll ans = 1e18;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        ll Y = calc(mid);
        ans = min(ans, abs(Y - sum));
        if (Y > sum)
        {
            // Y太大，要增大W，让Y变小
            l = mid + 1;
        }
        else
        {
            // Y<=S，减小W，让Y变大
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}