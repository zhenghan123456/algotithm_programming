#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
const int maxn = 4e5 + 10;
int diff[maxn];
ll nums[maxn];
struct
{
    ll s, t;
} s[maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int len = 0;
    _for(i, n)
    {
        cin >> s[i].s >> s[i].t;
        nums[len++] = s[i].s;
        nums[len++] = s[i].t + 1; // 关键：存 t+1，转为半开区间
    }
    sort(nums, nums + len);
    int tot = unique(nums, nums + len) - nums;

    _for(i, n)
    {
        int L = lower_bound(nums, nums + tot, s[i].s) - nums;
        int R = lower_bound(nums, nums + tot, s[i].t + 1) - nums;
        diff[L]++;
        diff[R]--;
    }

    ll ans = 0;
    int cover = 0;
    _for(i, tot - 1)
    {
        cover += diff[i];
        if (cover > 0)
        {
            ans += nums[i + 1] - nums[i];
        }
    }
    cout << ans << endl;
    return 0;
}