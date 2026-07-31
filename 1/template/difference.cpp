#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], diff[maxn];
int main()
{
    int n, x;
    cin >> x >> n;
    for (int i = 0; i < x; i++)
    {
        cin >> a[i];
    }
    diff[0] = a[0];
    for (int i = 1; i < x; i++)
    {
        diff[i] = a[i] - a[i - 1]; // 差分数组
    }
    for (int i = 0; i < n; i++)
    {
        int l, r, q;
        cin >> l >> r >> q;
        l--, r--; // 下标从0开始
        diff[l] += q;
        if (r + 1 < x)
            diff[r + 1] -= q; // 其实不需要判断r+1是否小于x，因为diff数组的长度是maxn，比题目上限多5，不会操作危险内存
    }
    for (int i = 1; i < x; i++)
    {
        diff[i] += diff[i - 1]; // 前缀和
    }
    for (int i = 0; i < x; i++)
    {
        cout << diff[i] << " ";
    }
}