#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

const int maxn = 4e4 + 10;
const int maxt = 20;
const int INF = 0x3f3f3f3f;

int n, k, m;
int a[maxn], b[maxn]; // a：原灯泡数组；b：异或差分数组
int len[105];         // 存储题目允许翻转的区间长度集合
vector<int> pos;      // 保存差分数组中值为1的所有关键点下标
int cost[maxt][maxt]; // cost[i][j]：第i个关键点到第j个关键点的最小操作步数
int dist[maxn];       // BFS单次遍历的距离数组
int dp[1 << maxt];    // 状态压缩DP数组，最多2^20种状态

void bfs(int st)
{
    memset(dist, 0x3f, sizeof(dist));
    queue<int> q;
    dist[st] = 0;
    q.push(st);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        // 遍历所有可用的跳跃长度
        _rep(i, 1, m + 1)
        {
            int l = len[i];
            int v = u + l;
            if (v <= n + 1 && dist[v] == INF)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
            v = u - l;
            if (v >= 1 && dist[v] == INF)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> m;
    memset(a, 0, sizeof(a));
    _rep(i, 1, k + 1)
    {
        int x;
        cin >> x;
        a[x] = 1;
    }
    _rep(i, 1, m + 1)
    {
        cin >> len[i];
    }

    // 异或差分
    _rep(i, 1, n + 2)
    {
        b[i] = a[i] ^ a[i - 1];
    }
    _rep(i, 1, n + 2)
    {
        if (b[i])
            pos.push_back(i);
    }
    int t = pos.size();

    memset(cost, 0x3f, sizeof(cost));
    _for(i, t)
    {
        // 算出到所有点距离
        bfs(pos[i]);
        _for(j, t)
        {
            cost[i][j] = dist[pos[j]];
        }
    }

    // dp[S]：S二进制标记已消除的点，值为消除这些点的最小操作次数
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0; // 初始没有点被消除，代价为0
    _for(S, 1 << t)
    {
        // 当前状态不可达，跳过
        if (dp[S] == INF)
            continue;

        // 找到第一个还未被配对消除的关键点i
        int i;
        for (i = 0; i < t; i++)
        {
            if (!(S & (1 << i)))
                break;
        }
        // 所有点都已配对完成
        if (i >= t)
            continue;

        // 枚举i后面未被使用的j，i和j配对抵消
        _rep(j, i + 1, t)
        {
            if (!(S & (1 << j)))
            {
                // 新状态：i和j都标记为已消除
                int nxt = S | (1 << i) | (1 << j);
                dp[nxt] = min(dp[nxt], dp[S] + cost[i][j]);
            }
        }
    }

    int ans = dp[(1 << t) - 1];
    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}