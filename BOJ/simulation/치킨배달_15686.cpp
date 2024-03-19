#include <bits/stdc++.h>

using namespace std;

int board[55][55];
pair<int, int> a[101]; // 집 위치
pair<int, int> b[14]; // 치킨 위치

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;

    int k = 0, l = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) a[k++] = {i, j};
            if (board[i][j] == 2) b[l++] = {i, j};
        }
    }

    int ans = 1000000;
    int b1[14] ={};
    fill(b1, b1 + l, 1);
    fill(b1, b1 + m, 0);
    do{
        int sum = 0;
        for (int i = 0; i < k; i++) {
            int length = 1000000;
            for (int j = 0; j < l; j++) {
                if(b1[j] == 1) continue;
                length = min(length, abs(a[i].first - b[j].first) + abs(a[i].second - b[j].second));
            }
            sum += length;
        }
        ans = min(ans, sum);
    }while(next_permutation(b1, b1 + l));
    
    cout << ans;
}