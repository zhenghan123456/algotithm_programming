#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 1; i <= n; i++)
#define _rep(i, a, b) for (int i = a; i <= b; i++)
#define endl '\n'
const int maxn = 125;
int matrix[maxn][maxn];
int pre[maxn][maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    _for(i, n) _for(j, n) cin >> matrix[i][j];

    _for(i, n) _for(j, n) pre[i][j] = matrix[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];

    int ans = INT_MIN;
    _for(i1, n) _for(j1, n) _rep(i2, i1, n) _rep(j2, j1, n) ans =
        max(ans, pre[i2][j2] - pre[i1 - 1][j2] - pre[i2][j1 - 1] + pre[i1 - 1][j1 - 1]);
    cout << ans << endl;
}