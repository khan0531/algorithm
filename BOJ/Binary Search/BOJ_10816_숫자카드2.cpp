#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    cin >> m;
    while(m--) {
        int k;
        cin >> k;

        auto lower = lower_bound(v.begin(), v.end(), k);
        auto upper = upper_bound(v.begin(), v.end(), k);

        cout << upper - lower<< ' ';
    }
}
