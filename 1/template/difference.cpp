#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn], diff[maxn];

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

    // 构建差分数组
    diff[0] = a[0];
    for (int i = 1; i < x; i++)
    {
        diff[i] = a[i] - a[i - 1];
    }

    // 批量处理区间修改操作
    for (int i = 0; i < n; i++)
    {
        int l, r, q;
        cin >> l >> r >> q;
        // 转换为0下标
        l--, r--;
        diff[l] += q;
        // r+1越界时无需抵消（无后续元素，不影响结果）
        if (r + 1 < x)
            diff[r + 1] -= q;
    }

    // 前缀和还原修改后的数组
    for (int i = 1; i < x; i++)
    {
        diff[i] += diff[i - 1];
    }

    // 输出结果
    for (int i = 0; i < x; i++)
    {
        cout << diff[i] << " ";
    }
    return 0;
}
