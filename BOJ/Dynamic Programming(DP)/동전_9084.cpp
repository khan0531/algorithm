#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[25] = {};
        int d[10005] = {};
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int m; cin >> m;
        d[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = a[i]; j <= m; j++) {
                d[j] += d[j - a[i]];
            }
        }
        cout << d[m] << '\n';
    }
}