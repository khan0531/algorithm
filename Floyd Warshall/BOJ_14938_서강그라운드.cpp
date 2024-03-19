#include <bits/stdc++.h>

using namespace std;

int n, m, r, a, b, l, ans;
const int MAX = 0x3f3f3f3f;
int d[105][105];
int item[105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        cin >> item[i];
    }
    
    for (int i = 1; i <= n; i++) {
        fill(d[i], d[i] + n + 1, MAX);
    }

    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }

    while(r--){
        cin >> a >> b >>l;
        d[a][b] = l;
        d[b][a] = l;
    }

    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            if (d[i][j] <= m) sum += item[j];
        }
        ans = max(ans, sum);
    }
    cout << ans;
}
