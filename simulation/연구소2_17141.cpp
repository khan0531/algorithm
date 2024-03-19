#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[55][55]; // 입력 받는 보드
int board2[55][55]; // 사용할 보드
int temp_board2[55][55]; // 사용할 보드 사용 전에 복사.
bool not_fill;
vector<pair<int, int>> virus; // 바이러스 놓을 수 있는 위치 저장
int a[15]; // 바이러스 놓을 수 있는 위치 중 랜덤하게 m개 뽑을 때 사용
int min_time = 1000000000;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) {
                virus.push_back({i, j});
                board2[i][j] = -1;
                temp_board2[i][j] = -1;
            }
            if(board[i][j] == 1) { // 벽
                board2[i][j] = -2;
                temp_board2[i][j] = -2;
            }
            else{
                board2[i][j] = -1;
                temp_board2[i][j] = -1;
            }
        }
    }

    int sz = virus.size();
    fill(a, a + sz, 1);
    fill(a, a + m, 0);

     do{
        not_fill = false;
        int mx = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < sz; i++) {
            if(a[i] == 1) continue;
            q.push(virus[i]);
            board2[virus[i].first][virus[i].second] = 0;
        }

        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(board2[nx][ny] != -1) continue;
                board2[nx][ny] = board2[cur.first][cur.second] + 1;
                q.push({nx, ny});
                mx = max(mx, board2[nx][ny]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(board2[i][j] != -1) continue;
                not_fill = true;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board2[i][j] = temp_board2[i][j];
            }
        }
        if(not_fill) continue;
        min_time = min(min_time, mx);

    }while(next_permutation(a, a + sz));

    if(min_time == 1000000000) cout << -1;
    else cout << min_time;
}