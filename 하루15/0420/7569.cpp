#include <bits/stdc++.h>

using namespace std;

int n, m, h, ans;
int board[105][105][105];
int dis[105][105][105];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;

    queue<tuple<int, int, int>> q;

    for (int k = 0; k < h; k++) { // 높이
        for (int i = 0; i < n; i++) { //세로
            for (int j = 0; j < m; j++){ //가로
                cin >> board[i][j][k];
                if (board[i][j][k] == 1) q.push({i, j, k});
            }
        }
    }

    while(!q.empty()){
        auto cur = q.front();
        auto [x, y, z] = cur;
        q.pop();

        for (int dir = 0; dir < 6; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if (board[nx][ny][nz] != 0) continue;
            board[nx][ny][nz] = 1;
            dis[nx][ny][nz] = dis[x][y][z] + 1;
            ans = max(ans, dis[nx][ny][nz]);
            q.push({nx, ny, nz});
        }
    }

    bool is_ripen = true;
    for (int k = 0; k < h; k++) { // 높이
        for (int i = 0; i < n; i++) { //세로
            for (int j = 0; j < m; j++){ //가로
                if (board[i][j][k] != 0) continue; 
                is_ripen = false;
                break;
            }
        }
    }

    if(!is_ripen) cout << -1;
    else cout << ans;
}
