#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 1; i <= n; i++)
#define _rep(i, a, b) for (int i = a; i <= b; i++)
#define endl '\n'
const int maxn = 1e7 + 10;
ll diff[maxn];
ll secdiff[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--)
    {
        ll l, r, s, e;
        scanf("%lld%lld%lld%lld", &l, &r, &s, &e);
        ll d = (e - s) / (r - l);
        secdiff[l] += s;
        secdiff[l + 1] += d - s;
        secdiff[r + 1] -= e + d;
        secdiff[r + 2] += e;
    }
    ll maxx = LLONG_MIN;
    ll ans = 0;
    _for(i, n)
    {
        diff[i] += ((secdiff[i] += secdiff[i - 1]) + diff[i - 1]);
        ans ^= diff[i];
        maxx = max(maxx, diff[i]);
    }
    cout << ans << ' ' << maxx << endl;
}