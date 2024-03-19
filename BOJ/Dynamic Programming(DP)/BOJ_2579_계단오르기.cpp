#include <bits/stdc++.h>

using namespace std;

int d[305];
int st[305];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> st[i];
    }

    d[1] = st[1];
    d[2] = st[1] + st[2];

    for (int i = 3; i <= n; i++) {
        d[i] = max(d[i - 2] + st[i], d[i - 3] + st[i - 1] + st[i]);
    }
    cout << d[n] << '\n';
}