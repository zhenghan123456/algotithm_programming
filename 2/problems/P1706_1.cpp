// 比较水的版本请各位不要参考
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
int a[10];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    _for(i, n) a[i] = i + 1;
    do
    {
        _for(i, n) cout << setw(5) << a[i];
        cout << endl;
    } while (next_permutation(a, a + n));
}