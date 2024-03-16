#include <bits/stdc++.h>

using namespace std;

int board[101][101];
bool vis[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m, n, k;
    cin >> m >> n >> k;

    while(k--){
        int startx, starty, endx, endy;
        cin >> startx >> starty >> endx >>endy;
        int a = m - 1 - starty;
        int b = startx;
        int c = m - endy;
        int d = endx - 1;

        for (int i = c; i <= a; i++) {
            for (int j = b; j <= d; j++) {
                board[i][j] = 1;
            }  
        }
    }

    int cnt = 0;
    vector<int> v;
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != 0 || vis[i][j]) continue;
            vis[i][j] = 1;
            q.push({i, j});
            cnt++;
            int area = 1;

            while(!q.empty()){
                auto cur = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (board[nx][ny] != 0 || vis[nx][ny]) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                    area++;
                }
            }
            v.push_back(area);
        }
    }

    cout << cnt << '\n';
    sort(v.begin(), v.end());
    for (int i: v) cout << i << ' '; 
}