#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int a[maxn], pre[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;

    // 读入原数组
    for (int i = 0; i < x; i++)
    {
        cin >> a[i];
    }

    // 预处理前缀和数组
    pre[0] = a[0];
    for (int i = 1; i < x; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }

    // 处理n次区间查询
    int l, r;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        // 适配0下标区间求和公式
        if (l == 0)
            cout << pre[r] << "\n";
        else
            cout << pre[r] - pre[l - 1] << "\n";
    }
    return 0;
}
