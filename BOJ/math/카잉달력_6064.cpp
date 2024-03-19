#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        
        int ans = 0;
        for (int i = x; i <= lcm(m, n); i += m) {
            if (y % n == 0 && i % n == 0){
                ans = i;
                break;
            }
            if (i % n == y){
                ans = i;
                break;
            }
        }
        if (ans == 0) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}