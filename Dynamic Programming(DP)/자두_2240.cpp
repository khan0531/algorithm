#include <bits/stdc++.h>

using namespace std;

int ja[1005];
int d[1005][32][3];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, w; cin >> t >> w;

    for (int i = 1; i <= t; i++) {
        cin >> ja[i];
    }

    for (int i = 1; i <= t; i++) {
        if(ja[i] == 1) {
            d[i][0][1] = d[i -1][0][1] + 1;
        }
        if(ja[i] == 2){
            d[i][0][1] = d[i - 1][0][1];
        }
        for (int j = 1; j <= w; j++) {
            if(j > i) break;
            if (ja[i] == 1 ){
                d[i][j][1] = max(d[i - 1][j][1], d[i - 1][j - 1][2]) + 1;
                d[i][j][2] = max(d[i - 1][j - 1][1], d[i - 1][j][2]);
            }
            if (ja[i] == 2){
                d[i][j][1] = max(d[i - 1][j][1], d[i - 1][j - 1][2]);
                d[i][j][2] = max(d[i - 1][j - 1][1], d[i - 1][j][2]) + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= w; i++) {
        ans = max(max(ans, d[t][i][1]), d[t][i][2]);
    }

    cout << ans;
}