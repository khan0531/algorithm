#include <bits/stdc++.h>

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;

    while(T--){
        int board[52][52] = {};
        bool vis[52][52];
        int M, N, K;
        for (int i = 0; i < N; i++) {
            fill(board[i], board[i] + M, 0);
            fill(vis[i], vis[i] + M, false);
        }
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        cin >> M >> N >> K;   // M- 가로, N- 세로

        while(K--){
            int X, Y;
            cin >> X >> Y; // X - 가로, Y - 세로
            board[Y][X] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] != 1 || vis[i][j]) continue;
                vis[i][j] = 1;
                queue<pair<int,int>> q;
                q.push({i,j});
                cnt++;

                while(!q.empty()){
                    pair<int, int> cur = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++){
                        int ny = cur.first + dy[dir];
                        int nx = cur.second + dx[dir];
                        if (ny < 0 || ny >= N || nx < 0 || nx >= M ) continue;
                        if (board[ny][nx] != 1 || vis[ny][nx]) continue;
                        vis[ny][nx] = 1;
                        q.push({ny,nx});
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
}