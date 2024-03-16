#include <bits/stdc++.h>

using namespace std;

string s[102];
bool vis[102][102];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// RRRBB
// GGBBB
// BBBRR
// BBRRR
// RRRRR

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++){
        cin >> s[i];
    }
    
    queue<pair<int, int>> r;
    int R = 0;
    queue<pair<int, int>> g;
    int G = 0;
    queue<pair<int, int>> b;
    int B = 0;
    queue<pair<int, int>> rg;
    int RG = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!vis[i][j]){
                if (s[i][j] == 'R'){
                    r.push({i, j});
                    vis[i][j] = 1;
                    R ++;

                    while(!r.empty()){
                        auto cur = r.front();
                        r.pop();

                        for (int dir = 0; dir < 4; dir ++){
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                            if (vis[nx][ny] || s[nx][ny] != 'R') continue;
                            vis[nx][ny] = 1;
                            r.push({nx, ny});
                        }
                    }
                }

                if (s[i][j] == 'G'){
                    g.push({i, j});
                    vis[i][j] = 1;
                    G ++;

                    while(!g.empty()){
                        auto cur = g.front();
                        g.pop();

                        for (int dir = 0; dir < 4; dir ++){
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                            if (vis[nx][ny] || s[nx][ny] != 'G') continue;
                            vis[nx][ny] = 1;
                            g.push({nx, ny});
                        }
                    }
                }

                if (s[i][j] == 'B'){
                    b.push({i, j});
                    vis[i][j] = 1;
                    B ++;

                    while(!b.empty()){
                        auto cur = b.front();
                        b.pop();

                        for (int dir = 0; dir < 4; dir ++){
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                            if (vis[nx][ny] || s[nx][ny] != 'B') continue;
                            vis[nx][ny] = 1;
                            b.push({nx, ny});
                        }
                    }
                }
            }
        }
    }

    cout << R + G + B << ' ';

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fill(vis[i], vis[i] + N, false);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!vis[i][j]){
                if (s[i][j] == 'R' || s[i][j] == 'G'){
                    rg.push({i, j});
                    vis[i][j] = 1;
                    RG ++;

                    while(!rg.empty()){
                        auto cur = rg.front();
                        rg.pop();

                        for (int dir = 0; dir < 4; dir ++){
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                            if (vis[nx][ny] || s[nx][ny] == 'B') continue;
                            vis[nx][ny] = 1;
                            rg.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    cout << RG + B;
}