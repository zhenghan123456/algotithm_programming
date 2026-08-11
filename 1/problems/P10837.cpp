#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

const int maxn = 2e5 + 10;
;

ll xs[maxn * 3];
int diff[maxn * 3];
// 区间结构体
struct seg
{
    ll l, r;
    int cnt;
} s[maxn * 3];

ll pre1[maxn * 3], pre2[maxn * 3];
pair<ll, ll> rose[maxn];

int totx, tots;
int n;
ll m;

int findl(ll x)
{
    int l = 0, r = tots;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (s[mid].l >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int findr(ll x)
{
    int l = 0, r = tots;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (s[mid].r <= x)
            l = mid + 1;
        else
            r = mid;
    }
    return l - 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    totx = 0;

    _for(i, n)
    {
        ll t;
        cin >> t;
        ll l = t;
        ll r = t + m - 1;
        rose[i].first = l;
        rose[i].second = r;
        xs[totx++] = l;
        xs[totx++] = r + 1;
    }

    // 离散化排序去重
    sort(xs, xs + totx);
    totx = unique(xs, xs + totx) - xs;

    memset(diff, 0, sizeof(diff));
    _for(i, n)
    {
        ll l = rose[i].first;
        ll r = rose[i].second;
        int pl = lower_bound(xs, xs + totx, l) - xs;
        int pr = lower_bound(xs, xs + totx, r + 1) - xs;
        diff[pl]++;
        diff[pr]--;
    }

    ll ans0 = 0;
    int cur_cnt = 0;
    tots = 0;
    _for(i, totx - 1)
    {
        cur_cnt += diff[i];
        ll l = xs[i];
        ll r = xs[i + 1] - 1;
        if (l > r)
            continue;
        s[tots].l = l;
        s[tots].r = r;
        s[tots].cnt = cur_cnt;
        ll len = r - l + 1;
        if (cur_cnt == 1)
            ans0 += len;
        tots++;
    }

    // 预处理前缀和
    pre1[0] = 0;
    pre2[0] = 0;
    _for(i, tots)
    {
        pre1[i + 1] = pre1[i];
        pre2[i + 1] = pre2[i];
        ll len = s[i].r - s[i].l + 1;
        if (s[i].cnt == 1)
            pre1[i + 1] += len;
        if (s[i].cnt == 2)
            pre2[i + 1] += len;
    }

    ll maxx = LLONG_MIN;
    _for(i, n)
    {
        ll l = rose[i].first;
        ll r = rose[i].second;

        int lp = findl(l);
        int rp = findr(r);

        ll loss = 0, gain = 0;

        if (lp <= rp)
        {
            loss += pre1[rp + 1] - pre1[lp];
            gain += pre2[rp + 1] - pre2[lp];
        }

        // 左侧不完整段
        if (lp - 1 >= 0)
        {
            int p = lp - 1;
            ll cl = max(s[p].l, l);
            ll cr = min(s[p].r, r);
            if (cl <= cr)
            {
                ll len = cr - cl + 1;
                if (s[p].cnt == 1)
                    loss += len;
                if (s[p].cnt == 2)
                    gain += len;
            }
        }

        // 右侧不完整段
        if (rp + 1 < tots)
        {
            int p = rp + 1;
            ll cl = max(s[p].l, l);
            ll cr = min(s[p].r, r);
            if (cl <= cr)
            {
                ll len = cr - cl + 1;
                if (s[p].cnt == 1)
                    loss += len;
                if (s[p].cnt == 2)
                    gain += len;
            }
        }

        ll delta = gain - loss;
        if (delta > maxx)
        {
            maxx = delta;
        }
    }

    ll final_ans = max(ans0, ans0 + maxx + m);
    cout << final_ans << endl;

    return 0;
}