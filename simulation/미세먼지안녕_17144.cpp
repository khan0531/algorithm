#include <bits/stdc++.h>

using namespace std;

int r, c, t, ans;
int a[55][55];
int a1[55][55]; // 미세먼지가 동시에 퍼지므로 복사본이 필요하다.
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0}; // dir 0: 오른쪽, 1 위, 2 왼쪽, 3 아래
queue<pair<int, int>> air; // 공기 청정기 저장
queue<pair<int, int>> q; //미세 먼지 저장

void dist(){
    //미세먼지 위치 저장
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(a[i][j] != 0 && a[i][j] != -1) q.push({i, j});
            a1[i][j] = a[i][j];
        }
    }
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int x = a[cur.first][cur.second]/5; // 퍼지는 미세먼지 양
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(a[nx][ny] == -1) continue;
            a1[nx][ny] += x;
            a1[cur.first][cur.second] -= x;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            a[i][j] = a1[i][j];
        }
    }
}

void wind(){
    //위에 회전
    auto cur = air.front();
    air.pop();
    air.push(cur);
    int x1 = cur.first - 1;
    while(x1 > 0){
        a[x1][0] = a[x1 - 1][0];
        x1--;
    }
    int y1 = 0;
    while(y1 < c - 1){
        a[0][y1] = a[0][y1 + 1];
        y1++;
    }
    int x2 = 0;
    while(x2 < cur.first){
        a[x2][c - 1] = a[x2 + 1][c - 1];
        x2++;
    }
    int y2 = c - 1;
    while(y2 > 1){
        a[cur.first][y2] = a[cur.first][y2 - 1];
        y2--;
    }
    a[cur.first][1] = 0;
    //아래 회전
    cur = air.front();
    air.pop();
    air.push(cur);
    int x3 = cur.first + 1;
    while(x3 < r - 1){
        a[x3][0] = a[x3 + 1][0];
        x3++;
    }
    int y3 = 0;
    while(y3 < c - 1){
        a[r - 1][y3] = a[r - 1][y3 + 1];
        y3++;
    }
    int x4 = r - 1;
    while(x4 > cur.first){
        a[x4][c - 1] = a[x4 - 1][c - 1];
        x4--;
    }
    int y4 = c - 1;
    while(y4 > 1){
        a[cur.first][y4] = a[cur.first][y4 - 1];
        y4--;
    }
    a[cur.first][1] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> t;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
            if(a[i][j] == -1) air.push({i, j}); 
        }
    }
    while(t--){
        dist();
        wind();
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ans += a[i][j];
        }
    }
    cout << ans + 2;
}