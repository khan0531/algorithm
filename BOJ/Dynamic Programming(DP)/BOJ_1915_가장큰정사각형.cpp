#include <bits/stdc++.h>

using namespace std;

int n, m;
string s[1005];
int board[1005][1005];
int d[1005][1005]; //i,j 를 오른쪽 아래 꼭지점으로 포함하는 사각형의 한변의 길이
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 1; j <= m; j++) {
            board[i][j] = s[i][j] - '0';
            d[i][j] = board[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(board[i][j] == 1) d[i][j] = min({d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]}) + 1;
            ans = max(ans, d[i][j]);
        }
    }
    
    cout << ans*ans;
}