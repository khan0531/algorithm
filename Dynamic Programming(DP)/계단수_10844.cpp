#include <bits/stdc++.h>

using namespace std;

long long d[105][10];
long long ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >>n;

    d[1][0] = 0;
    for (int i = 1; i <= 9; i++) {
        d[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        d[i][0] = d[i - 1][1];
        d[i][9] = d[i - 1][8];
        for (int j = 1; j <= 8; j++) {
            d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1])%1000000000;
        }
    }

    for (int i = 0; i <= 9; i++) {
        ans += d[n][i]%1000000000;
    }
    cout << ans%1000000000;
}