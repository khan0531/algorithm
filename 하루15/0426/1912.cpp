#include <bits/stdc++.h>

using namespace std;

int n, a, mx = -100000;
int d[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        d[i] = max(d[i - 1] + a, a);
        mx = max(mx, d[i]);
    }
    cout << mx;
}
