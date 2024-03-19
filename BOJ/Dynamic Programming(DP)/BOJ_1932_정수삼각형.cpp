#include <bits/stdc++.h>

using namespace std;

int d[505][505];
int a[505][505];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> a[i][j];
            d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + a[i][j];
        }
    }

    sort(d[n - 1], d[n - 1] + n);

    cout << d[n - 1][n - 1];
}