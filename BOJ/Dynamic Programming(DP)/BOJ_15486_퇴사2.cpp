#include <bits/stdc++.h>

using namespace std;

int d[1500005]; // d[i]: i번째 상품까지 고려했을 때의 최대 가치를 저장하는 배열
int n; // 상품의 개수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; // 상품의 개수 입력

    // 각 상품의 정보 입력 및 처리
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b; // 상품의 필요 시간과 얻을 수 있는 가치 입력
        d[i] = max(d[i], d[i - 1]); // 이전 상태(d[i-1])와 현재 상태(d[i])를 비교하여 최대 가치 갱신
        if (i + a - 1 > n) continue; // 배열 범위를 초과하는 경우 처리하지 않음
        d[i + a - 1] = max(d[i + a - 1], d[i - 1] + b); // i번째 상품을 선택했을 때의 최대 가치를 업데이트
    }

    cout << d[n]; // 모든 상품을 고려했을 때의 최대 가치 출력
    
    return 0;
}
