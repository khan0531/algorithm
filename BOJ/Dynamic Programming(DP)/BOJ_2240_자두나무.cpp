#include <bits/stdc++.h>

using namespace std;

int d[1001][31]; // d[i][j]: i초까지 j번 움직였을 때 최대 자두 개수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, w, a;
    cin >> t >> w;

    for (int i = 1; i <= t; i++) {
        cin >> a;

        d[i][0] = d[i - 1][0]; // 움직임이 없을 때의 최대 자두 개수는 이전 상태와 동일
        if (a == 1) d[i][0]++; // 현재 나무가 1번째 나무라면 자두가 떨어지므로 개수 증가

        for (int j = 1; j <= w; j++) { // 최대 움직임 수까지 반복
            d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]); // 이전 상태의 최대 자두 개수 중 최댓값으로 초기화
            if ((j + a) % 2) d[i][j]++; // 나무 번호와 횟수가 홀수인 경우에만 자두를 받을 수 있음
        }
    }

    cout << *max_element(d[t], d[t] + w + 1); // 최대 자두 개수 출력
}
