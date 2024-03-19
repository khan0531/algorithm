#include <bits/stdc++.h>

using namespace std;

bool isPalindromeDP(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i+1]) dp[i][i+1] = true;
    }

    for (int len = 2; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = len + i;
            if (s[i] == s[j] && dp[i+1][j-1]) dp[i][j] = true;
        }
    }

    return dp[0][n-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    cout << isPalindromeDP(s);
}