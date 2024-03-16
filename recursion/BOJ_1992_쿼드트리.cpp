#include <bits/stdc++.h>

using namespace std;

string board[70];
string ans;

bool check(int N , int x, int y) {
    for (int i = x; i < x + N; i++)
    for (int j = y; j < y + N; j++) 
    if (board[i][j] != board[x][y]) return false;
    return true;
}

void func(int N , int x, int y){
    if (check(N, x, y)){
        ans += board[x][y];
        return;
    }
    
    ans += '(';
    int n = N / 2;
    for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    func(n, x + n * i, y + n * j);
    ans += ')';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    cin >> board[i];
    
    func(N, 0, 0);

    cout << ans;
}