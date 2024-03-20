#include <bits/stdc++.h>

using namespace std;

int dp[105][105][105]; // dp[i][j][k] : 첫번째 문자열에서 i번째 문자까지 탐색, 두번째 문자열에서 j번째 문자까지 탐색 했을 때의 LCS 값, 세번째 ...

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b, c;
    cin >> a >> b >> c;

    int len1 = a.length();
    int len2 = b.length();
    int len3 = c.length();

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            for (int k = 1; k <= len3; k++) {
                if (a[i-1] == b[j-1] && a[i-1] == c[k-1]) dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else  dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
            }
        }
    }
    cout << dp[len1][len2][len3];
}