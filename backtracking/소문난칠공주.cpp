#include <bits/stdc++.h>

using namespace std;

string s[5];
int cnt;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool vis[30][30];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < 5; i++) {
        cin >> s[i];
    }

    queue<pair<int, int>> q;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if(vis[i][j]) continue;
            string ans = {};
            ans += s[i][j];
            q.push({i, j});
            vis[i][j] = true;

            while(!q.empty()){
                auto cur = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir ++){
                    int nx = i + dx[dir];
                    int ny = i + dy[dir];
                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                    if (vis[nx][ny]) continue;
                    ans += s[nx][ny];
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
            int som = 0;
            for (char c: ans){
                if (c == 's') som ++;
            }
            if (cnt >= 4) cnt++;




        }
    }
}