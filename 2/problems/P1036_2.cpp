#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
const int maxn = 25;
int x[maxn];
int n, k;
bool isprime(int n)
{
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;
    if (!(n & 1))
        return 0;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (!(n % i))
            return 0;
    }
    return 1;
}
int dfs(int depth, int val, int sum)
{
    if (depth == k)
        return isprime(sum);
    int cnt = 0;
    _rep(i, val + 1, n + depth - k + 1) cnt += dfs(depth + 1, i, sum + x[i]);
    return cnt;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    _for(i, n) cin >> x[i];
    sort(x, x + n);
    cout << dfs(0, -1, 0) << endl;
}