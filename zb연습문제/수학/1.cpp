#include <bits/stdc++.h>

using namespace std;

int n;
int d[105][105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int>v[105];
    cin >> n;

    for (int i = 1; i <= n; i++) {
        d[i][1] = 1;
        d[i][i] = 1;
    }

    for (int i = 3; i <= n; i++) {
        for (int j = 2; j < n; j++) {
            d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= i + 1; j++) {
            v[i].push_back(d[i + 1][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j : v[i]) cout << j << ' ';
        cout <<'\n';
    }
    
}
