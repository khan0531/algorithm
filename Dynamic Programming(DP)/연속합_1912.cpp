#include <bits/stdc++.h>

using namespace std;

int d[100005];
int a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = a[i];
    }
    
    int ans = -1001;
    for (int i = 1; i <= n; i++) {
            d[i] = max(d[i], d[i - 1] + a[i]);
            ans = max(ans, d[i]);
    }

    cout << ans;
}