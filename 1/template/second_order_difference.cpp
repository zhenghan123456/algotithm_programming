#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn], diff[maxn], secdiff[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // 构建一阶差分
    diff[0] = a[0];
    for (int i = 1; i < n; i++)
        diff[i] = a[i] - a[i - 1];
    // 构建二阶差分
    secdiff[0] = diff[0];
    for (int i = 1; i < n; i++)
        secdiff[i] = diff[i] - diff[i - 1];

    while (q--)
    {
        int l, r, v;
        cin >> l >> r >> v;
        l--, r--; // 转为0-based
        secdiff[l] += v;
        if (r + 1 < n)
            secdiff[r + 1] -= v * (r - l + 2);
        if (r + 2 < n)
            secdiff[r + 2] += v * (r - l + 1);
    }
    // 第一次前缀和：二阶差分 → 一阶差分
    for (int i = 1; i < n; i++)
        diff[i] = secdiff[i] + diff[i - 1];
    // 第二次前缀和：一阶差分 → 原数组
    a[0] = diff[0];
    for (int i = 1; i < n; i++)
        a[i] = a[i - 1] + diff[i];

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
