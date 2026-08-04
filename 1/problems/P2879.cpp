#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 1; i <= n; i++)
#define _rep(i, a, b) for (int i = a; i <= b; i++)
#define endl '\n'
const int maxn = 1e4 + 10;
int diff[maxn];
set<pair<int, int>> cansee; // set去重
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, i, h, r;
    cin >> n >> i >> h >> r;
    diff[1] = h;
    while (r--)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        cansee.insert(make_pair(a, b));
    }
    for (auto &i : cansee)
    {
        int a = i.first;
        int b = i.second;
        diff[a + 1]--;
        diff[b]++;
    }
    // 还原差分
    _for(i, n)
    {
        diff[i] += diff[i - 1];
        cout << diff[i] << endl;
    }
}