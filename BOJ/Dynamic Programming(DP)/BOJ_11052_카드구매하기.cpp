#include <bits/stdc++.h>

using namespace std;

int n;
int p[1005];
int d[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        d[i] = p[i];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i/2; j++) {
            d[i] = max(d[i], d[i - j] + d[j]);
        }
    }
    cout << d[n];
}