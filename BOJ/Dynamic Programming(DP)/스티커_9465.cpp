#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int board[3][100005] = {};
        int d[3][100005] = {};
        for (int i = 1; i < 3; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> board[i][j];
            }
        }
        for (int j = 1; j <= n; j++) {
            for (int i = 0; i < 3; i++) {
                d[i][j] = max(d[(i + 1)%3][j - 1], d[(i + 2)%3][j - 1]) + board[i][j];
            }
        }
        int ans = max({d[0][n], d[1][n], d[2][n]});
        cout << ans << '\n';
    }
}