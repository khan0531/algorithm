#include <iostream>
using namespace std;

int n;

bool isPrime(int k) {
    if (k == 1) return false;
    for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) return false;
    }
    return true;
}

void dfs(int k, int a) {
    if (k == n) {
        if (isPrime(a)) cout << a << '\n';
        return;
    }

    for (int i = 1; i < 10; i++) {
        if (i != 2 && i % 2 == 0) continue; // 짝수이면서 2가 아닌 경우 제외
        int cur = 10 * a + i; // 현재 숫자에 i를 추가하여 새로운 숫자 생성
        if (!isPrime(cur)) continue; // 현재 숫자가 소수가 아니라면 무시
        dfs(k + 1, cur); // 다음 단계로 깊이 우선 탐색
    }
}

int main() {
    cin >> n;
    dfs(0, 0);
    return 0;
}
