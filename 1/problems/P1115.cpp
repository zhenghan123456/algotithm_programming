#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
const int maxn = 2e5 + 10;
int a[maxn], pre[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    _for(i, n) cin >> a[i];
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + a[i];
    ll ans = 0;
    int maxx = INT_MIN;
    _for(i, n - 1)
    {
        _rep(j, i + 1, n)
        {
            int sum = pre[j] - pre[i];
            if (maxx < sum)
                maxx = sum;
        }
    }
    cout << sum << endl;
    return 0;
}