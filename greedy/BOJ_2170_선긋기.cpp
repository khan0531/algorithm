#include <bits/stdc++.h>

using namespace std;

int n, mx;
long long ans;
pair<int, int> p[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n);
    ans = p[0].second - p[0].first;
    mx = p[0].second;
    for (int i = 1; i < n; i++) {
        if(p[i].first < mx){
            if(p[i].second <= mx) continue;
            ans += (p[i].second - mx);
            mx = p[i].second;
        }
        else {
            ans += (p[i].second - p[i].first);
            mx = p[i].second;
        }
    }
    cout << ans;
}   