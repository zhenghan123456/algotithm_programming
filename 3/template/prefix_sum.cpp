#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn], pre[maxn];
int main()
{
    int x, n;
    cin >> x >> n;
    for (int i = 0; i < x; i++)
    {
        cin >> a[i];
    }
    pre[0] = a[0];
    for (int i = 1; i < x; i++)
    {
        // 对于这种题还可以原地操作，不过不建议
        pre[i] = pre[i - 1] + a[i];
    }
    int l, r;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << endl;
    }
}