#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
const int maxn = 100010;
int p[maxn];
struct rail
{
    int a, b, c;
} a[maxn];
int cities[maxn];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i].a >> a[i].b >> a[i].c;
    }
    for (int i = 0; i < m - 1; i++)
    {
        int last = p[i + 1];
        cities[min(p[i], last)]++;
        cities[max(p[i], last)]--;
    }
    for (int i = 1; i < n; i++)
    {
        cities[i] += cities[i - 1];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        rail &c = a[i];
        ans += min(ll(c.a) * cities[i], c.c + ll(c.b) * cities[i]);
    }
    cout << ans << '\n';
    return 0;
}