#include <bits/stdc++.h>

using namespace std;

bool isused[1000005];
long long ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        pair<int, int> p[1000005] = {};
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            p[i] = {- i, a};
        }
        ans = 0;
        fill(isused, isused + n, false);
        sort(p, p + n);

        for (int i = 0; i < n; i++) {
            if(isused[i]) continue;
            isused[i] = true;
            for (int j = i + 1; j < n; j++) {
                if(isused[j] || p[i].second < p[j].second) break;
                isused[j] = true;
                ans += (p[i].second - p[j].second);
            }
        }
        cout << ans << '\n';
    }
    
}