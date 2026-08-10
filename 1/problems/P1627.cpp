#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
ll cnt_left[maxn * 2], cnt_right[maxn * 2];
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll b;
    cin >> n >> b;
    vector<ll> arr(n);
    int pos = -1; // 记录第一个b出现的下标
    _for(i, n)
    {
        cin >> arr[i];
        if (pos == -1 && arr[i] == b)
            pos = i;
    }

    int offset = n;
    // 第一步：统计b左侧所有前缀和（0 ~ pos-1）
    int sum = offset;
    cnt_left[sum] = 1;
    _for(i, pos)
    {
        if (arr[i] > b)
            sum++;
        else if (arr[i] < b)
            sum--;
        cnt_left[sum]++;
    }

    // 第二步：统计b及右侧所有前缀和（pos ~ n-1）
    _rep(i, pos, n)
    {
        if (arr[i] > b)
            sum++;
        else if (arr[i] < b)
            sum--;
        cnt_right[sum]++;
    }

    ll ans = 0;
    _rep(i, 0, 2 * n + 1)
    {
        ans += cnt_left[i] * cnt_right[i];
    }
    cout << ans << endl;
    return 0;
}