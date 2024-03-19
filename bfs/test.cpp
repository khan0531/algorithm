//이거는 정답은 나오는데 제출하니 틀린 것.
#include <bits/stdc++.h>

using namespace std;

string s[27];
bool vis[27][27];
int area[600];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    queue<pair<int, int>> q;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (s[i][j] == '0' || vis[i][j]) continue;
            vis[i][j] = 1;
            q.push({i, j});
            cnt ++;

            while(!q.empty()){
                auto cur = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir ++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (s[nx][ny] == '0' || vis[nx][ny]) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                    area[cnt] ++;
                }
            }
        }
    }
    
    cout << cnt <<'\n';
    sort(area, area + cnt);
    for (int i = 1; i <= cnt; i++) {
        cout << area[i] << '\n';
    }
}