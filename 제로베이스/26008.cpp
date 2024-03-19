#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, a, h;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> a;
    cin >> h;

    ll ans = 1;
    for (int i = 0; i < n - 1; i++) {
        ans *= m;
        ans %= 1'000'000'007;
    }

    cout << ans;
}
