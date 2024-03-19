#include <bits/stdc++.h>

using namespace std;

const int MAX = 0x7f7f7f7f;
int n, m;
int d[105][105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i <= n; i++) {
        fill(d[i], d[i] + n + 1, MAX);
        d[i][i] = 0;
    }

    cin >> n >> m;
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        if (d[a][b] > c) d[a][b] = c;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
}