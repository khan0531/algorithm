#include <bits/stdc++.h>

using namespace std;

bool board[16][16];
int n;
int cnt = 0;

void check(int i, int j){
    for(int dir = 0; dir < n; dir ++){
        int nx = i + 1 * dir;
        if (nx >= n) continue;
        board[nx][j] = 1;
    }

    for(int dir = 0; dir < n; dir ++){
        int ny = j + 1 * dir;
        if (ny >= n) continue;
        board[i][ny] = 1;
    }

    for(int dir = 0; dir < n; dir ++){
        int nx = i - 1 * dir;
        if (nx < 0) continue;
        board[nx][j] = 1;
    }

    for(int dir = 0; dir < n; dir ++){
        int ny = j - 1 * dir;
        if (ny < 0) continue;
        board[i][ny] = 1;
    }

    for(int dir = 0; dir < n; dir ++){
        int nx = i + 1 * dir;
        int ny = j + 1 * dir;
        if (nx >=n || ny >= n) continue;
        board[nx][ny] = 1;
    }

    for(int dir = 0; dir < n; dir ++){
        int nx = i - 1 * dir;
        int ny = j - 1 * dir;
        if (nx < 0 || ny < 0) continue;
        board[nx][ny] = 1;
    }

    for(int dir = 0; dir < n; dir ++){
        int nx = i + 1 * dir;
        int ny = j - 1 * dir;
        if (nx >= n || ny < 0) continue;
        board[nx][ny] = 1;
    }

    for(int dir = 0; dir < n; dir ++){
        int nx = i - 1 * dir;
        int ny = j + 1 * dir;
        if (nx <0 || ny >= n) continue;
        board[nx][ny] = 1;
    }

    return;
}

void func(int k){
    if (k == n){
        cnt ++;
        return;
    }
    
    pair<int, int> temp = {};
    for (int i = 0; i < n; i++) {
        if (board[k][i]) continue;
        if(temp.first == k && temp.second == i) continue;
        board[k][i] = true;
        temp.first = k;
        temp.second = i;
        check(k, i);
        func(k + 1);

        for (int j = 0; j < n; j ++) fill(board[j], board[j] + n, 0); // 이게 틀림
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    // check(0, 0);
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    func(0);
    cout << cnt;
 
}