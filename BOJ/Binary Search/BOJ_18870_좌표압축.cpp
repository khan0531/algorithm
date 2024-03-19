#include <bits/stdc++.h>

using namespace std;

long long a[1000005];
vector<long long> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        long long k;
        cin >> k;
        a[i] = k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    for (int i = 0; i < n; i++) {
        cout << lower_bound(v.begin(), v.end(), a[i]) - v.begin() << ' ';
    }
}