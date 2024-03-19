#include <bits/stdc++.h>

using namespace std;

int t, n, m, k, x, y;
int board[55][55];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--) {
        cin >> m >> n >> k;

        for (int i = 0; i < n; i++) {
            fill(board[i], board[i] + m, 0);
        }

        while(k--){
            cin >> y >> x;
            board[x][y] = 1;
        }

        int cnt = 0;

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != 1) continue;
                board[i][j] = 2;
                cnt++;
                q.push({i, j});

                while (!q.empty()) {
                    auto cur = q.front();
                    auto [x, y] = cur;
                    q.pop();
                    
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (board[nx][ny] != 1) continue;
                        board[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
}
