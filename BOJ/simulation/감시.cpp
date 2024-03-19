#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int cnt; // 감시 영역의 넓이
int cctv_cnt; // cctv 개수
int wall_cnt; // 벽 개수
int mx; // 감시 영역 최대값
int ans;
vector<pair<int, int>> cctv; // cctv를 모아둔다.
int board[10][10];
bool check[10][10];
bool tmp_check[10][10][10];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void watch(int x, int y, int dir){ // x, y 지점에서 dir 방향으로 감시해라, 0: 동, 1:남, 2:서, 3: 북
    while(true){
        x += dx[dir];
        y += dy[dir];
        if(x < 0 || x >=n || y < 0 || y >= m) break;
        if(board[x][y] == 6) break;
        if(check[x][y] || board[x][y] != 0) continue;
        check[x][y] = true;
    }
}

void func(int k){
    if(k == cctv_cnt){
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(check[i][j]) cnt++;
            }
        }
        mx = max(mx, cnt);
        return;
    }
    int x = cctv[k].first;
    int y = cctv[k].second;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tmp_check[k][i][j] = check[i][j]; // 감시하기 전 상태 저장.
        }
    }
    for (int dir = 0; dir < 4; dir++) {
        if(board[x][y] == 1){
            watch(x, y, dir);
        }
        if(board[x][y] == 2){
            watch(x, y, dir);
            watch(x, y, (dir + 2)%4);
        }
        if(board[x][y] == 3){
            watch(x, y, dir);
            watch(x, y, (dir + 1)%4);
        }
        if(board[x][y]== 4){
            watch(x, y, dir);
            watch(x, y, (dir + 1)%4);
            watch(x, y, (dir + 2)%4);
        }
        if(board[x][y] == 5){
            watch(x, y, 0);
            watch(x, y, 1);
            watch(x, y, 2);
            watch(x, y, 3);
        }
        func(k + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                check[i][j] = tmp_check[k][i][j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 6) wall_cnt++;
            if(board[i][j] != 0 && board[i][j] != 6) cctv.push_back({i, j}); //cctv 미리 저장, 넣어둔다.
        }
    }
    cctv_cnt = cctv.size();
    func(0);
    ans = n*m - mx - cctv_cnt - wall_cnt;
    cout << ans;
}