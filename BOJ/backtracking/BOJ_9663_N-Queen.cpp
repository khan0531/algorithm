#include <bits/stdc++.h>

using namespace std;

int n;
int cnt = 0;
bool isused_1[35]; // 열
bool isused_2[35]; //오른쪽 대가선
bool isused_3[35]; // 왼쪽 대각선

void func(int k){
    if (k == n){
        cnt ++;
        return;
    }
    // y가 같으면 안됨, x+y가 같으면 안됨, x-y가 같으면 안됨
    for (int i = 0; i < n; i++) { // i는 y 좌표, k는 x 좌표
        if(isused_1[i] || isused_2[k + i] || isused_3[n + k - i]) continue;
        isused_1[i] = true;
        isused_2[k + i] = true;
        isused_3[n + k - i] = true;
        func(k + 1);
        isused_1[i] = false;
        isused_2[k + i] = false;
        isused_3[n + k - i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    func(0);
    cout << cnt;
}