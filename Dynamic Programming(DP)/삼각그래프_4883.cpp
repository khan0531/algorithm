#include <bits/stdc++.h>

using namespace std;

int board[100010][3];
long long d[100010][3];
long long cnt = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        int n; cin >> n;
        if(n == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> board[i][j];
            }
        }
        d[0][0] = 10000000;
        d[0][1] = board[0][1];
        d[0][2] = board[0][2] + d[0][1];
        for (int i = 1; i < n; i++) {
            d[i][0] = min(d[i - 1][0], d[i - 1][1]) + board[i][0];
            d[i][1] = min({d[i - 1][0], d[i - 1][1], d[i - 1][2], d[i][0]}) + board[i][1];
            d[i][2] = min({d[i - 1][1], d[i - 1][2], d[i][1]}) + board[i][2];
        }
        cout << cnt << '.'<< ' ' << d[n - 1][1] << '\n';
        cnt++;
    }
}