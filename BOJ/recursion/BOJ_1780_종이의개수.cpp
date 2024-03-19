#include <bits/stdc++.h>

using namespace std;

int paper[2200][2200];
int cnt[3]; // 0: -1의 개수, 1: 0의 개수, 2: 1의 개수

bool check(int n, int x, int y){
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y+ n; j++) {
            if (paper[x][y] != paper[i][j]) return false;
        }
    }
    return true;
}

void func(int b, int x, int y){
    if (check(b, x, y)){
        cnt[paper[x][y] + 1] ++;
        return; 
    }

    else {
        int n = b / 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                func(n, x + i * n, y + j * n);
            }
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

    for (int i = 0; i < 3; i++) {
     cout << cnt[i] << '\n';   
    }
}