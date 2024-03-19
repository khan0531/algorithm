#include <bits/stdc++.h>

using namespace std;

long long ans;
long long d[1005][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    fill(d[1], d[1] + 10, 1);
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = j; k < 10; k++){
                d[i][k] += d[i - 1][j]%10007;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        ans += d[n][i]%10007;
    }
    cout << ans%10007;
}