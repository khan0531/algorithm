#include <bits/stdc++.h>

using namespace std;

pair<int, int> p[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >>n;

    for (int i = 0; i < n; i++) {
        cin >> get<0>(p[i]) >> get<1>(p[i]);
    }

    sort(p, p + n);
    for (int i = 0; i < n; i++) {
        cout << get<0>(p[i]) << ' ' << get<1>(p[i]) << '\n';
    }
}