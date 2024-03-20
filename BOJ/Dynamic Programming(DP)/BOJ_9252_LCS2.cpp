#include <bits/stdc++.h>

using namespace std;

int dp[1'005][1'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    int len1 = a.length();
    int len2 = b.length();

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[len1][len2] << '\n';

    int i = len1, j = len2;
    string lcs = "";
    while(i > 0 && j > 0) {
        if (dp[i-1][j] == dp[i][j]){
            i--;
        }
        else if (dp[i][j-1] == dp[i][j]) {
            j--;
        }
        else {
            lcs += a[i-1];
            i--;
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs;
}