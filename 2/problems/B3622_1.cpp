#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    // 从全0串开始
    _for(i, 1 << n)
    {
        // 判断每一位是否为1
        for (int j = n - 1; j >= 0; j--) // 从高位开始
        {
            int x = (1 << j);
            cout << ((x & i) ? 'Y' : 'N');
        }
        cout << endl;
    }
}