#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, cnt, ans;
ll a[2005];
bool is_used[2005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int lb = lower_bound(a, a + n, a[i] + a[j]) - a;
            while (lb == i || lb == j || is_used[lb]) lb++;
            if (a[lb] == a[i] + a[j] && lb < n) {
                int ub = upper_bound(a + lb, a + n, a[i] + a[j]) - a;
                cnt = ub - lb;
                ans += cnt;
                for (int i = lb; i < ub; i++) {
                    is_used[i] = true;
                }
            }
        }
    }
    cout << ans;
}

