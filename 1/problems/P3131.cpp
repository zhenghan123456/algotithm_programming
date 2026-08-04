#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 1; i <= n; i++)
#define _rep(i, a, b) for (int i = a; i <= b; i++)
#define endl '\n'
const int maxn = 5e4 + 10;
int a[maxn], pre[maxn];
int fst[7], lst[7]; // 第一次和最后一次出现索引对应数的位置（first，last）
int main()
{
    // 初始化数组
    memset(fst + 1 /*0比较特殊*/, -1, sizeof(fst) - sizeof(int));
    memset(lst, -1, sizeof(lst));

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    _for(i, n)
    {
        cin >> a[i];
        a[i] %= 7;
    }

    // 初始化pre数组
    _for(i, n)
    {
        pre[i] = a[i] + pre[i - 1];
        pre[i] %= 7;
    }

    _for(i, n)
    {
        if (fst[pre[i]] == -1)
            fst[pre[i]] = i;
    }
    for (int i = n; i > 0; i--)
    {
        if (lst[pre[i]] == -1)
            lst[pre[i]] = i;
    }
    int ans = INT_MIN;
    for (int i = 0; i < 7; i++)
    {
        ans = max(ans, lst[i] - fst[i]);
    }
    cout << ans << endl;
}