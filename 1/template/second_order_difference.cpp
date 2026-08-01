#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], diff[maxn], secdiff[maxn];
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    diff[0] = secdiff[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        diff[i] = a[i] - a[i - 1]; // 一阶差分
    }
    for (int i = 1; i < n; i++)
    {
        secdiff[i] = diff[i] - diff[i - 1]; // 二阶差分
    }
    for (int i = 0; i < q; i++)
    {
        int l, r, v;
        cin >> l >> r >> v;
        l--, r--;
        secdiff[l] += v;
        secdiff[r + 1] -= v * (r - l + 2);
        secdiff[r + 2] += v * (r - l + 1);
    }
    // 将二阶差分还原为一阶差分
    for (int i = 1; i < n; i++)
    {
        diff[i] = secdiff[i] + secdiff[i - 1];
    }
    // 将一阶差分还原为原数组
    for (int i = 1; i < n; i++)
    {
        a[i] = diff[i] + diff[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}