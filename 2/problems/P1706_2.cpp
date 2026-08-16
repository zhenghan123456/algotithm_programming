#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
bool vis[10]; // 数据范围比较小也不用考虑用vector<bool>状态压缩
int a[10];
int n; // dfs函数要用就设为全局
void dfs(int depth)
{
    _for(i, n)
    {
        if (!vis[i])
        {
            if (depth == n)
            {
                // 递归到底，输出
                a[depth - 1] = i + 1;
                _for(i, n) cout << setw(5) << a[i];
                cout << endl;
                return;
            }
            vis[i] = true;
            a[depth - 1] = i + 1;
            dfs(depth + 1);

            vis[i] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    dfs(1);
    return 0;
}