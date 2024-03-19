#include <bits/stdc++.h>

using namespace std;

string s[12];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int cnt;
int ans;

void func2(int a, int b){
    for (int i = 1; i < 12; i++) {
        if(a + i > 11 || s[a + i][b] != '.') break;
        s[a + i][b] = s[a + i - 1][b];
        s[a + i - 1][b] = '.';
    }
    return;
}

void func(int a, int b){
    bool isused[12][12] = {};
    queue<pair<int, int>> q;
    q.push({a, b});
    isused[a][b] = true;
    int sum = 0;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        sum ++;

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx > 11 || ny < 0 || ny > 5 ) continue;
            if (s[nx][ny] != s[a][b] || isused[nx][ny]) continue;
            q.push({nx, ny});
            isused[nx][ny] = true;
        }
    }

    if(sum < 4) return;
    cnt++;
    for (int i = 11; i >= 0; i--) {
        for (int j = 5; j >= 0; j--) {
            if (!isused[i][j]) continue;
            s[i][j] = '.';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 12; i++) {
        cin >> s[i];
    }
    while(true){
        int cur = ans;
        cnt = 0;
        for (int i = 11; i >= 0; i--) {
            for (int j = 5; j >= 0; j--) {
                if(s[i][j] == '.') continue;
                func(i, j);
            }
        }
        if (cnt != 0) ans++;
        for (int i = 11; i >= 0; i--) {
            for (int j = 5; j >= 0; j--) {
                if(s[i][j] == '.') continue;
                func2(i, j);
            }
        }
        if(cur == ans) break;
    }
    cout << ans;
}