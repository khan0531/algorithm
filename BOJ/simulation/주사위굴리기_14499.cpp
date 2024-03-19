#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, k;
int board[25][25];
int dice[6] = {0, 0, 0, 0, 0, 0};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void func(int nx, int ny, int i){ //보드판 숫자, 주사위 숫자 바꾸기, i는 상단
    if(board[nx][ny] == 0){
        board[nx][ny] = dice[5 - i];
    }
    else{
        dice[5 - i] = board[nx][ny];
        board[nx][ny] = 0;
    }
}

void moving(int& nx, int& ny, int dir, int& i, int& j, int& l){ //동서남북 이동, 그리고 주사위 i는 상단, j는 우측, l은 위쪽
    nx += dx[dir - 1];
    ny += dy[dir - 1];
    if(nx < 0 || nx >= n || ny < 0 || ny >= m){
        nx -= dx[dir - 1];
        ny -= dy[dir - 1];
    }
    else{
        int cur = i, cur2 = j, cur3 = l;
        if (dir == 1){
            i = 5- cur2;
            j = cur;
            l = cur3;
        }
        if (dir == 2){
            i = cur2;
            j = 5 - cur;
            l = cur3;
        }
        if (dir == 3){
            i = 5 - cur3;
            j = cur2;
            l = cur; 
        }
        if (dir == 4){
            i = cur3;
            j = cur2;
            l = 5 - cur;
        }
        cout << dice[i] << '\n';
        func(nx, ny, i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int a = 0, b = 2, c = 1; 

    for (int i = 0; i < k; i++) {
        int dir;
        cin >> dir;
        moving(x, y, dir, a, b, c);
    }
}