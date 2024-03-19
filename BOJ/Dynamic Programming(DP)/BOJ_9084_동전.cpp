#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        int a[25] = {}; // 동전의 가치를 저장하는 배열
        int d[10005] = {}; // 금액 i를 만들 수 있는 경우의 수를 저장하는 배열 (금액 범위: 1 ~ 10000)
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int m;
        cin >> m;
        d[0] = 1; // 금액이 0일 때의 경우의 수는 1 (아무 동전도 사용하지 않는 경우)
        for (int i = 1; i <= n; i++) { // 각 동전 가치에 대해 반복
            for (int j = a[i]; j <= m; j++) { // 현재 동전으로 만들 수 있는 금액부터 목표 금액까지 반복
                d[j] += d[j - a[i]]; // 현재 금액을 만들 수 있는 경우의 수를 누적
            }
        }
        cout << d[m] << '\n';
    }
}
