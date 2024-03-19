#include <bits/stdc++.h>

using namespace std;

int m, n, k, cnt;
int board[105][105];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> area;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;
    
    int x1, x2, y1, y2;
    while(k--){
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = (m - 1) - (y2 - 1); i <= (m - 1) - y1; i++) {
            for (int j = x1; j <= (x2 - 1); j++) {
                board[i][j] = 1;
            }
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != 0) continue;
            else {
                q.push({i, j});
                board[i][j] = 3;
                int a = 0;

                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    a++;

                    for (int dir = 0; dir < 4; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if (board[nx][ny] != 0) continue;
                        board[nx][ny] = 3;
                        q.push({nx, ny});
                    }
                }
                area.push_back(a);
            }
        }
    }

    sort(area.begin(), area.end());

    cout << area.size() <<'\n';
    for(int ans : area){
        cout << ans << ' ';
    }
}
