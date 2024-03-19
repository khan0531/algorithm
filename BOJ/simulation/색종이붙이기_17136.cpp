#include <bits/stdc++.h>

using namespace std;

int n;
const int MAX = 0x7f7f7f7f;
int mn = MAX;
int board[15][15];
int d[15][15];
int a[15][15];
int sz[6];
bool vis[15][15];
vector<pair<int, int>> v;

void func1(int x, int y){
    cout << x << ' ' << y << ' ' << a[x][y]<<'\n';
    for (int i = 0; i < a[x][y]; i++) {
        for (int j = 0; j < a[x][y]; j++) {
            d[x-i][y-j] = 0;
        }
    }
    // if (a[x][y] == 1) d[x][y] = a[x][y];
    sz[a[x][y]]++;
}

void func2(int x, int y){
    sz[a[x][y]]--;
    for (int i = 0; i < a[x][y]; i++) {
        for (int j = 0; j < a[x][y]; j++) {
            d[x-i][y-j] = board[x-i][y-j];
        }
    }
    d[x][y] = --a[x][y];
}

void func(int k){
    if (k == n){
        int cnt = 0;
        for (int i = 1; i <= 5; i++){
            cout << i << ' ' << sz[i] << '\n';
            // if (sz[i] > 5) return;
            cnt += sz[i];
        }
        mn = min(mn, cnt);
        return;
    }

    for (auto [x, y] : v) {
        if (d[x][y] <= 0) continue;
        func1(x, y);

        // cout << x << ' ' << y << ' ' << a[x][y]<< ' '<< k <<'\n';
        func(k+a[x][y]*a[x][y]);

        func2(x, y);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
            if (i == 0 || j == 0) continue;
            if (board[i][j] == 0) continue;
            if (board[i-1][j] != 0 && board[i][j-1] != 0 && board[i-1][j-1] != 0) 
                board[i][j] = min({board[i-1][j], board[i][j-1], board[i-1][j-1], 4}) + 1;
                d[i][j] = board[i][j];
                a[i][j] = board[i][j];
                // for (int k = 0; k < board[i][j]; k++){
                //     v.push_back({i, j});
                // }
                n++;
        }
    }

    reverse(v.begin(), v.end());
    // for (auto [x, y] : v) cout << x << ' ' << y << '\n';
    func(0);

    if (mn == MAX) cout << -1;
    else cout << mn;
}
    // cout << '\n';
    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 10; j++) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }