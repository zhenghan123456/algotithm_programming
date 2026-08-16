#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
const int maxn = 410;
int board[maxn][maxn];
int px[] = {2, 2, -2, -2, 1, 1, -1, -1};
int py[] = {1, -1, 1, -1, 2, -2, 2, -2};
int n, m, x, y;
bool in(int x, int lo, int hi)
{
    return x >= lo && x < hi;
}
void dfs(int x, int y, int step /*相当于depth */)
{
    _for(i, 8)
    {
        if (!in(x + px[i], 0, n) || !in(y + py[i], 0, m))
            continue;
        if (board[x + px[i]][y + py[i]] == -1)
        {
            board[x + px[i]][y + py[i]] = step;
            dfs(x + px[i], y + py[i], step + 1);
        }
        else if (step < board[x + px[i]][y + py[i]])
        {
            board[x + px[i]][y + py[i]] = step;
            dfs(x + px[i], y + py[i], step + 1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x >> y;
    _for(i, n)
    {
        memset(board[i], -1, sizeof(board[i]));
    }
    x--;
    y--;
    board[x][y] = 0;
    dfs(x, y, 1);
    _for(i, n)
    {
        _for(j, m) cout << board[i][j] << ' ';
        cout << endl;
    }
}