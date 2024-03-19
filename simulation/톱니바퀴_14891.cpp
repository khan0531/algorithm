#include <bits/stdc++.h>

using namespace std;

string s[4];
int k;
int ans;
int dx[4];

void func(int x, int dir){
    dx[x] = dir;

    for (int i = 0; i < 4; i++) {
        if(x + i >= 3 || s[x + i][2] == s[x + i + 1][6]) break;
        else{
            dx[x + i + 1] = -dx[x + i];
        }
    }

    for (int i = 0; i < 4; i++) {
        if(x - i <= 0 || s[x - i][6] == s[x - i - 1][2]) break;
        else{
            dx[x - i - 1] = -dx[x - i];
        }
    }
}

void func1(string& str){ // 시계 방향으로 돌려, 1 일 때
    char cur = str[0];
    str[0] = str[7];
    for (int i = 7; i > 1; i--) {
        str[i] = str[i - 1];
    }
    str[1] = cur;
}

void func2(string& str){ //반시계 방향으로 돌려, -1 일 때
    char cur = str[0];
    str[0] = str[1];
    for (int i = 2; i <= 7; i++) {
        str[i - 1] = str[i];
    }
    str[7] = cur;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; i++) {
        cin >> s[i];
    }


    cin >> k;
    while(k--){
        int a, b;
        cin >> a >> b;
        fill(dx, dx + 4, 0);

        func(a - 1, b);
        for (int i = 0; i < 4; i++) {
            if (dx[i] == 0) continue;
            if (dx[i] == 1) func1(s[i]);
            else func2(s[i]);
        }
    }

    for (int i = 0; i < 4; i++) {
        if(s[i][0] == '0') continue;
        ans += (1 << i);
    }
    cout << ans;
}
