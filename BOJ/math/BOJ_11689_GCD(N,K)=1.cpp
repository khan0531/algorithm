#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll ans = n;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0) continue;
        ans -= ans / i; // i가 n의 소인수인 경우, 오일러 파이 함수 공식에 따라 값을 갱신
        while (n % i == 0) {
            n /= i; // n을 i의 최대 거듭제곱으로 나눔
        }
    }
    if (n > 1) ans -= ans / n; // 남은 n이 1보다 크면, n은 n의 소인수이므로, 공식에 따라 값을 갱신
    cout << ans << endl;

    return 0;
}
