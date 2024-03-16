#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    int board[502][502] = {};
    bool vis[502][502];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 0, mx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != 1 || vis[i][j]) continue;
            cnt++;

            queue<pair<int,int>> q;
            q.push({i, j});
            vis[i][j] = 1;
            int area = 0;

            while(!q.empty()){
                pair<int, int> cur = q.front();
                q.pop();
                area++;
                for (int dir = 0; dir < 4; dir++){
                    int nx = cur.first + dx[dir];
                    int my = cur.second + dy[dir];
                    if (nx < 0 || nx > n || my < 0 || my > m) continue;
                    if (vis[nx][my] || board[nx][my] != 1) continue;
                    q.push({nx, my});
                    vis[nx][my] = 1;
                }
            }
            mx = max(mx, area);
        }
    }
    cout << cnt << '\n' << mx;

}