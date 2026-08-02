#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;

int main()
{
    int n;
    cin >> n;
    long long sum = 0;   // 当前前缀和s[r]
    long long min_s = 0; // 最小前缀和，初始s[0]=0
    long long ans = -INF;
    for (int i = 1; i <= n; ++i)
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