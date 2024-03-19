#include <bits/stdc++.h>

using namespace std;

int n;
int a[1'000'005];
int d[1'000'005];
int idx;
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        idx = lower_bound(d+1, d + ans + 1, a[i]) - d;
        d[idx] = a[i];
        if (idx == ans+1) ans++;
    }
    cout << ans;
}
