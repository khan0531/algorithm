#include <bits/stdc++.h>

using namespace std;

int a[20005];
int b[20005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        sort(b, b + m);
        for (int i = 0; i < n; i++) {
            int idx = lower_bound(b, b + m, a[i]) - b;
            ans += idx;
        }
        cout << ans << '\n';
    }
}