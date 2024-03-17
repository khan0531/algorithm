#include <bits/stdc++.h>

using namespace std;

int v, e;
const int MAX = 0x3f3f3f3f;
int d[405][405];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> v >> e;

    for (int i = 1; i <= v; i++) {
        fill(d[i], d[i] + v + 1, MAX);
    }

    for (int i = 1; i <= v; i++) {
        d[i][i] = 0;
    }

    int a, b, c;
    while(e--){
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    for (int k = 1; k <= v; k++){
        for (int i= 1; i <= v; i++){
            for (int j = 1; j <= v; j++){
                if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    int ans = MAX;
    for (int i = 1; i < v; i++) {
        for (int j = i + 1; j <= v; j++) {
            ans = min(ans, d[i][j] + d[j][i]);
        }
    }
    if (ans == MAX) cout << -1;
    else cout << ans;
}
