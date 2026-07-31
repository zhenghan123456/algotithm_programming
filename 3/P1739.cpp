#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> s;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            s.push('(');
        else if (str[i] == ')')
            if (!s.empty())
                s.pop();
            else
            {
                puts("NO");
                return 0;
            }
    }
    if (s.empty())
        puts("YES");
    else
        puts("NO");
}