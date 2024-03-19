#include <bits/stdc++.h>

using namespace std;


string board[102];
bool vis[102][102];
int ans[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = 1;
    ans[0][0] = 1;

    while(!vis[N - 1][M - 1]){
        pair<int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int my = cur.second + dy[dir];
            if (nx < 0 || nx >= N || my < 0 || my >= M) continue;
            if (board[nx][my] != '1' || vis[nx][my]) continue;
            vis[nx][my] = 1;
            q.push({nx, my});
            ans[nx][my] = ans[cur.first][cur.second] + 1;
        }
    }

    cout << ans[N - 1][M - 1];
}