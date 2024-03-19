#include <bits/stdc++.h>

using namespace std;

int n, g_cnt,cnt; // cnt는 겹치는 변의 갯수
int board[105][105];
bool vis[105][105];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) g_cnt++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) continue;
            vis[i][j] = true;
            
            for (int idx = 0; idx < 4; idx++) {
                int nx = i + dx[idx];
                int ny = j + dy[idx];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (vis[nx][ny] || board[nx][ny] != 1) continue;
                cnt++;
            }
        }
    }

    cout << 4*g_cnt - 2*cnt;
}
