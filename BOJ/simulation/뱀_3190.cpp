#include <bits/stdc++.h>

using namespace std;

int n, k, L;
int board[105][105];
bool isused[105][105]; // 뱀이면 true, 뱀 아니면 false
char order[10005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> snake;
int ans = 1;

//L은 왼쪽으로 돌려라, D는 오른쪽으로 돌려라 ' '(공백)은 전진해라
void func(int& x, int& y, int& dir, char c){ //dir은 동 0 남 1 서 2 북 3 방향, 머리 움직여라
    x += dx[dir];
    y += dy[dir];
    if (c == 'L') dir = (dir + 3) % 4;
    if (c == 'D') dir = (dir + 1) % 4;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        board[a - 1][b - 1] = 1; // 사과 위치
    }
    cin >> L;
    for (int i = 1; i <= L; i++) {
        int a;
        char c;
        cin >> a >> c;
        order[a] = c;
    }

    snake.push({0, 0});
    isused[0][0] = true;
    int x = 0, y = 0, dir = 0;
    for (int i = 1; i < 10005; i++) {

        func(x, y, dir, order[i]);
        if (x < 0 || x >=n || y < 0 || y >= n || isused[x][y] == true) {
            cout << ans;
            break;
        }
        isused[x][y] = true;
        snake.push({x, y});

        if (board[x][y] == 0){
            auto cur = snake.front();
            isused[cur.first][cur.second] = false;
            snake.pop();
        }
        board[x][y] = 0;
        ans ++;
    }
}