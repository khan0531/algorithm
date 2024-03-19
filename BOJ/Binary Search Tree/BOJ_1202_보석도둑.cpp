#include <bits/stdc++.h>

using namespace std;

int n, k;
long long ans;
pair<int, int> val[300005];
multiset<int> bag;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> val[i].second >> val[i].first;
    }
    while(k--){
        int a; cin >> a;
        bag.insert(a);
    }
    sort(val, val + n, greater<pair<int, int>>());
    for (int i = 0; i < n; i++) {
        auto it = bag.lower_bound(val[i].second);
        if(it == bag.end()) continue;
        ans += val[i].first;
        bag.erase(it);
    }
    cout << ans;
}