#include <bits/stdc++.h>
using namespace std;
char nums[] = {'0', '1', '2', '3', '4', '5', '6', '7',
               '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
map<char, int> mp = {{'0', 0},  {'1', 1},  {'2', 2},  {'3', 3},
                     {'4', 4},  {'5', 5},  {'6', 6},  {'7', 7},
                     {'8', 8},  {'9', 9},  {'A', 10}, {'B', 11},
                     {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}};
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int num = 0;
	for (int i = 0; i < s.length(); i++) {
		num *= n;
		num += mp[s[i]];
	}
	int m;
	cin >> m;
	string ans;
	while (num) {
		ans += nums[num % m];
		num /= m;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}