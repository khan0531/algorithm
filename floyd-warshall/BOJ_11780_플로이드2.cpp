#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, c;
const int MAX = 0x3f3f3f3f;
int d[105][105];
int nxt[105][105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> m;

    for (int i = 1; i <= n; i++) fill(d[i], d[i] + n + 1, MAX);
    
    for (int i = 1; i <= n; i++) d[i][i] = 0;

    while(m--){
        cin >> a >> b >> c;
        if (d[a][b] > c) d[a][b] = c;
        nxt[a][b] = b;
    }

    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == MAX) d[i][j] = 0;
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == 0) {
                cout << 0 << '\n';
                continue;
            }

            vector<int> path;
            int st = i;
            while(st != j) {
                path.push_back(st);
                st = nxt[st][j];
            }
            path.push_back(j);
            cout << path.size() << ' ';
            for (int ans : path) cout << ans << ' ';
            cout << '\n';
        }
    }
}
