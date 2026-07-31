#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    deque<int> d;
    set<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (s.find(x) == s.end())
        {
            d.push_back(x);
            s.insert(x);
            if (d.size() > m)
            {
                s.erase(s.find(d.front()));
                d.pop_front();
            }
            ans++;
        }
    }
    cout << ans << endl;
}