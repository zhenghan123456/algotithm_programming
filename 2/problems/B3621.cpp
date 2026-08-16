#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[6]; // n最大5，开6足够

void dfs(int depth)
{
    // 递归终点：已经填完n个位置，直接输出
    if (depth == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }

    // 当前位置枚举 1~k 所有数，可重复选，不用vis
    for (int num = 1; num <= k; num++)
    {
        a[depth] = num;
        dfs(depth + 1); // 填下一位
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    dfs(0);
    return 0;
}