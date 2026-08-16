#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
int n;
bool a[10];
void dfs(int depth)
{
    if (depth == n)
    {
        _for(i, n) cout << (a[i] ? 'Y' : 'N');
        cout << endl;
        return;
    }
    a[depth] = 0;
    dfs(depth + 1);
    a[depth] = 1;
    dfs(depth + 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    dfs(0);
}