#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
const int maxn = 1e5 + 10;
int a[maxn];
int diff[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    _for(i, n) cin >> a[i];
    _for(i, m)
    {
        bool opt;
        cin >> opt;
        if (opt == 1)
        {
            int l, r, k, d;
            cin >> l >> r >> k >> d;
            diff[l] += k;
            diff[l + 1] += (d - k);
            diff[r + 1] -= ((r - l + 1) * d + k);
            diff[r + 2] += ((r - l) * d + k);
        }
        else
        {
            int q;
            cin >> q;
            ll s1 = 0, s2 = 0;
            for (int i = 1; i <= q; ++i)
            {
                s1 += diff[i];
                s2 += 1LL * diff[i] * i;
            }
            ll add = 1LL * (q + 1) * s1 - s2;
            cout << a[q - 1] + add << '\n';
        }
    }
}