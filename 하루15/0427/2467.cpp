#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a, a + n);
    ll ans1 = 1000000001;
    ll ans2 = 1000000001;

    for (int i = 0; i < n; i++) {
        int idx = lower_bound(a, a + n, -a[i]) - a;
        if (idx - 1 >= 0 && idx - 1 != i && abs(a[i] + a[idx - 1]) <= abs(ans1 + ans2)){
            ans1 = a[i];
            ans2 = a[idx - 1];
        }
        if (idx + 1 < n && idx + 1 != i && abs(a[i] + a[idx + 1]) <= abs(ans1 + ans2)){
            ans1 = a[i];
            ans2 = a[idx + 1];
        }
        if (idx < n && idx != i && abs(a[i] + a[idx]) <= abs(ans1 + ans2)){
            ans1 = a[i];
            ans2 = a[idx];
        }
    }
    if (ans1 > ans2) swap(ans1, ans2);
    cout << ans1 << ' ' << ans2;
}
