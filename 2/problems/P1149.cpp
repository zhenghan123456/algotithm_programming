#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
int sticks[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n;
int sticknum(int n)
{
    int res = 0;
    do
    {
        res += sticks[n % 10];
        n /= 10;
    } while (n);
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    n -= 4;
    int cnt = 0;
    _for(a, 1000)
    {
        _for(b, 1000)
        {
            int s = a + b;
            if (sticknum(a) + sticknum(b) + sticknum(s) == n)
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}