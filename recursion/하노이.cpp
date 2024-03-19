#include <bits/stdc++.h>

using namespace std;

int n;
int board[2200][2200];
int cnt[3];

void func(int n, int x, int y) {
    bool same = true;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (board[i][j] != board[x][y]) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) cnt[board[x][y] + 1]++;
    else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                func(n/3, x + n/3*i, y + n/3*j);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    func(n, 0, 0);

    for (int i = 0; i < 3; i++) {
        cout << cnt[i] <<'\n';
    }
}
