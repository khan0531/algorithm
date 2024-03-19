#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int board[55][55];
bool clean[55][55];
int n, m, r, c, d;
int ans;

bool check(int x, int y){ // 주변 칸 중 청소 안한 부분 있으면 false, 모두 청소 했으면 true
    bool alreadyclean = false;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(board[nx][ny] == 1) {
            alreadyclean = true;
            continue;
        }
        if(!clean[nx][ny]) {
            alreadyclean = false;
            break;
        }
        else alreadyclean = true;
    }
    return alreadyclean;
}

void func(int& x, int& y, int dir){ // k 방향으로 이동해라
    x += dx[dir];
    y += dy[dir];
}

bool check2(int x, int y, int dir){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >=m) return false;
        if(clean[nx][ny] || board[nx][ny] == 1) return false;

        return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) clean[i][j] = true;
        }
    }
    
    queue<pair<int, int>> q;
    clean[r][c] = true;
    int dir = d;
    q.push({r, c});

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        if(check(cur.first, cur.second)){
            func(cur.first, cur.second, (dir+2)%4);
            if(cur.first < 0 || cur.first >= n || cur.second < 0 || cur.second >=m || board[cur.first][cur.second] == 1) break;
            if(!clean[cur.first][cur.second]) ans++;
            clean[cur.first][cur.second] = true;
            q.push(cur);
        }

        else{
            do{
                dir = (dir+3)%4;
            }while(!check2(cur.first, cur.second, dir));
            func(cur.first, cur.second, dir);
            ans++;
            clean[cur.first][cur.second] = true;
            q.push(cur);
        }
    }
    cout << ans + 1;
}