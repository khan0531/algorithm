#include <bits/stdc++.h>

using namespace std;

int d[1500005];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        d[i] = max(d[i], d[i - 1]);
        if (i + a - 1 > n) continue;
        d[i + a - 1] = max(d[i + a - 1], d[i - 1] + b);
    }

    cout << d[n];    
}