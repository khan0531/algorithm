#include <bits/stdc++.h>

using namespace std;

int n, l, r;
int ans;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int a[55][55];
bool isused[55][55]; // bfs 돌 때 사용

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    while(true){
        bool wide_is = false; // 너비가 모두 1이면 아웃할 것.
        queue<pair<int, int>> q; // bfs 도는것
        queue<pair<int, int>> q2;// bfs를 돌고 인구 분배할 때 쓸 것.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(isused[i][j]) continue;
                int cnt = 1;
                int sum = a[i][j];
                q.push({i, j});
                q2.push({i, j});
                isused[i][j] = true;
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || nx >= n || ny <0 || ny >= n) continue;
                        int abs_num = abs(a[cur.first][cur.second] - a[nx][ny]);
                        if(abs_num < l || abs_num > r) continue;
                        if(isused[nx][ny]) continue;
                        q.push({nx, ny});
                        q2.push({nx, ny});
                        sum += a[nx][ny];
                        cnt++;
                        isused[nx][ny] = true;
                        wide_is = true;
                    }
                }
                //if(q2.size() == 1) continue;
                while(!q2.empty()){
                    auto cur = q2.front();
                    q2.pop();
                    a[cur.first][cur.second] = sum/cnt;
                }
            }
        }
        if(!wide_is) break;
        ans++;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                isused[i][j] = false;
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << ans;
}