#include <bits/stdc++.h>

using namespace std;

int paper[150][150];
int cnt[2]; // 0: 0의 개수 흰색, 1: 1의 개수 파란색

bool check(int N, int x, int y){
    for (int i = x; i < x + N; i++){
        for (int j = y; j < y + N; j++){
            if (paper[x][y] != paper[i][j]) return false;
        }
    }
    return true;
}

void func(int N, int x, int y){
    if (check(N, x, y)){
        cnt[paper[x][y]] ++;
        return;
    }

    int n = N / 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            func(n, x + i * n, y + j * n);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    func(N, 0, 0);

    for (int i = 0; i < 2; i++) {
        cout << cnt[i] << '\n';   
    }
}