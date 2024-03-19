#include <bits/stdc++.h>

using namespace std;


bool manecher(string s) {
    int n = s.size();
    vector<int> dp(n, 0);

    string tmp = "0";
    for (int i = 0; i < s.size(); i++) {
        tmp += s[i];
        tmp += "0";
    }
    int sz = tmp.size();

    int r = 0, p = 0;
    for (int i = 0; i < sz; i++) {
        if (i > r) dp[i] = 0;
        else dp[i] = min(dp[2*p - i], r - i);
        while (i - dp[i] - 1 >= 0 && i+dp[i]+1 < sz && tmp[i - dp[i] - 1] == tmp[i+dp[i]+1]) dp[i]++;

        if (i+dp[i] > r) {
            r = i + dp[i];
            p = i;
        }
    }

    return dp[n - 1];

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    cout << manecher(s);
    
}