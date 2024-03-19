#include <bits/stdc++.h>

using namespace std;

int n;
int cnt;
int board[20][20];
int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};

// dir: 0 가로 / 1 세로 / 2 대각선
void func(int x, int y, int d){ // x,y는 끝점, d는 x,y로 도달할 때의 방향.
    if(x == n -1 && y == n - 1){
        cnt++;
        return;
    }
    for(int dir = 0; dir < 3; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(d == 0) if(dir == 1) continue;
        if(d == 1) if(dir == 0) continue;
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(board[nx][ny] == 1) continue;
        if(dir == 2) if(board[x + 1][y] == 1 || board[x][y + 1] == 1) continue;
        func(nx, ny, dir);
}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    func(0, 1, 0);
    cout << cnt;
}