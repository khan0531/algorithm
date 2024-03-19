#include <bits/stdc++.h>

using namespace std;

int d[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    d[1] = 0;

    int n; cin >> n;

    for (int i = 2; i <= n; i++) {
        if (i % 3 == 0 && i % 2 == 0) d[i] = min(min(d[i/2] + 1, d[i/3] + 1), d[i - 1] + 1);
        if (i % 3 == 0 && i % 2 != 0) d[i] = min(d[i/3] + 1, d[i - 1] + 1);
        if (i % 3 != 0 && i % 2 == 0) d[i] = min(d[i/2] + 1, d[i - 1] + 1);
        if (i % 3 != 0 && i % 2 != 0) d[i] = d[i - 1] + 1;
    }

    cout << d[n];
}