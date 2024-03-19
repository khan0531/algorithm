#include <bits/stdc++.h>

using namespace std;

//dir 0 -> 1 -> 2 -> 3 -> 0 : (dir + 1) % 4
int dx[4] = {0, -1, 0, 1}; // y좌표에 더할 것.
int dy[4] = {1, 0, -1, 0}; // x좌표에 더할 것.
bool isused[105][105];
int cnt;

bool check(int x, int y){
    if(isused[x][y] && isused[x + 1][y] && isused[x][y + 1] && isused[x + 1][y + 1]) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    while(n--){
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        vector<int> dir = {}; //세대가 거듭할 수록 진행되는 dir을 저장
        isused[x][y] = true;
        dir.push_back(d);
        x += dy[d];
        y += dx[d];
        isused[x][y] = true;

        for (int i = 1; i <= g; i++) {
            for (int j = (1 << (i - 1)) - 1; j >= 0; j--) {
                dir.push_back((dir[j] + 1)%4);
                x += dy[(dir[j] + 1)%4];
                y += dx[(dir[j] + 1)%4];
                isused[x][y] = true;
            }
        }
    }
    for (int i = 0; i <= 99; i++) {
        for (int j = 0; j <= 99; j++) {
            if(check(i, j)) cnt++;
        }
    }
    cout << cnt;
}