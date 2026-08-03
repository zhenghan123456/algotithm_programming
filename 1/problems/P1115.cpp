#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
const int maxn = 2e5 + 10;
int main()
{
    int n;
    cin >> n;
    long long sum = 0;   // 当前前缀和s[r]
    long long min_s = 0; // 最小前缀和，初始s[0]=0
    long long ans = INT_MIN;
    while (n--)
    {
        int x;
        cin >> x;
        sum += x; // sum = s[i]
        ans = max(ans, sum - min_s);
        min_s = min(min_s, sum);
    }
    cout << ans << endl;
    return 0;
}