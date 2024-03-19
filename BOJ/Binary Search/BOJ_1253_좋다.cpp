#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, cnt;
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
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            int lb = lower_bound(a, a + n, a[i] - a[j]) - a;
            while (lb == i || lb == j) lb++;
            if (lb < n && a[lb] == a[i] - a[j]) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
}