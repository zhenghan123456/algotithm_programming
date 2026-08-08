#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
// c[0][s]：未遇到b时，前缀和为s的出现次数
// c[1][s]：已经遇到过b之后，前缀和为s的出现次数
ll c[2][maxn]; // 题目未明确数据范围，用ll更稳妥
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll b, ans;
    cin >> n >> b;

    c[0][n] = 1;
    // flag标记：是否已经读取到数值b，0未遇到，1已遇到
    bool flag = 0;
    // s为偏移后的前缀和：大于b记+1，小于b记‑1；初始偏移n防止下标为负
    int s = n;

    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        // 当前数不等于b：更新偏移前缀和
        if (a != b)
            s += a > b ? 1 : -1;
        c[flag |= (a == b)][s]++; // 一旦碰到b，flag永久置1；
    }

    ans = 0;
    // 注意：合法子数组要求子数组包含b，
    for (int i = 0; i < 2 * n; i++)
    {
        ans += c[0][i] * c[1][i];
    }
    cout << ans << endl;
    return 0;
}