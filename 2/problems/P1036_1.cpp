#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
const int maxn = 25;
int x[maxn];
bool isp(int n)
{
    if (n < 2)
        return 0;
    if (n == 2)
        return 1; // 特判
    if (!(n & 1))
        return 0;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (!(n % i))
            return 0;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    _for(i, n) cin >> x[i];
    int num = 1 << n;
    int cnt = 0;
    _for(i, num)
    {
        if (__builtin_popcount(i) != k)
            continue;
        int sum = 0;
        _for(j, n)
        {
            bool flag = (i & (1 << j));
            sum += flag * x[j];
        }
        cnt += isp(sum);
    }
    cout << cnt << endl;
}