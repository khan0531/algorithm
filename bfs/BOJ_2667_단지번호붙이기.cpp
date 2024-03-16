#include <bits/stdc++.h>

using namespace std;

string s[27];
bool vis[27][27];
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

    int cnt = 0;
    vector<int> v;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (s[i][j] != '1' || vis[i][j]) continue;
            queue<pair<int, int>> q;
            vis[i][j] = true;
            q.push({i, j});
            int area = 0;
            cnt ++;

            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                area ++;

                for (int dir = 0; dir < 4; dir ++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (s[nx][ny] != '1' || vis[nx][ny]) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            v.push_back(area);
        }
    }
    
    cout << cnt <<'\n';
    sort(v.begin(), v.end());
    for (int i : v) cout << i << '\n';
}