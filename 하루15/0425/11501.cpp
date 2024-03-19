#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t, n;
int w[1000005];
int ww[1000005];
int lb[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--){
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> w[i];
            ww[i] = w[i];
        }

        sort(ww, ww + n);
        for (int i = 0; i < n; i++) {
            lb[i] = lower_bound(ww, ww + n, w[i]) - ww;
        }

        int maxlb = lb[n - 1];
        ll ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (lb[i] <= maxlb) {
                ans += ww[maxlb] - w[i];
                // cout << maxlb << ' ' << i <<' ' << ww[maxlb] - w[i] << '\n';
            }

            else maxlb = lb[i];
        }

        cout << ans << '\n';
        fill(w, w + n, 0);
        fill(ww, ww + n, 0);
        fill(lb, lb + n, 0);
    }
}
