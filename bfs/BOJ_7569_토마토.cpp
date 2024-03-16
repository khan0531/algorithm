#include <bits/stdc++.h>

using namespace std;

int board[102][102][102];
int dis[102][102][102];
int M, N, H;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> M >> N >> H; // 세로 n x i /가로 m y j / 높이 h z h

    queue<tuple<int,int,int>> q;

    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++){
                cin >> board[i][j][k];
                if (board[i][j][k] == 1) q.push({i,j,k});
                if (board[i][j][k] == 0) dis[i][j][k] = -1;
            }
        }
    }

    while(!q.empty()){
        auto [x, y, z] = q.front();
        q.pop();

        for (int dir = 0; dir < 6; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
            if (dis[nx][ny][nz] >= 0) continue;
            q.push({nx, ny, nz});
            dis[nx][ny][nz] = dis[x][y][z] + 1;
        }
    }
    
    int mx = 0;
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++){
                if (dis[i][j][k] < 0){
                    cout << -1;
                    return 0;
                }
                mx = max(mx, dis[i][j][k]);
            }
        }
    }
    cout << mx;
    return 0;
}