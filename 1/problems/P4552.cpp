#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
const int maxn = 1e5 + 10;
ll a[maxn], diff[maxn]; // 别忘了long long
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    _for(i, n)
    {
        cin >> a[i];
    }
    // 初始化差分
    diff[0] = a[0];
    _rep(i, 1, n)
    {
        diff[i] = a[i] - a[i - 1];
    }
    ll x = 0, y = 0; // 正数和、负数和
    _rep(i, 1, n)
    {
        if (diff[i] > 0)
            x += diff[i];
        else
            y -= diff[i];
    }
    cout << max(x, y) << '\n' << llabs(x - y) + 1 << '\n';
}