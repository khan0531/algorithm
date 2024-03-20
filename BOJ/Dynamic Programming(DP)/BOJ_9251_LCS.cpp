#include <bits/stdc++.h>

using namespace std;

int dp[1'005][1'005]; // dp[i][j] : 첫번째 문자열에서 i번째 문자까지 탐색, 두번째 문자열에서 j번째 문자까지 탐색 했을 때의 LCS 값

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    for (int i = 1; i <= s.length(); i++) {
        for (int j = 1; j <= t.length(); j++) {
            if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout << dp[s.length()][t.length()];
}