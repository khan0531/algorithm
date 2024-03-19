#include <bits/stdc++.h>

using namespace std;

bool d[2005][2005];
int a[2005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        d[i][i] = true;
    }
    for (int i = 1; i <= n - 1; i++) {
        if (a[i] == a[i + 1]) d[i][i + 1] = true;
    }
    for (int k = 2; k <= n - 1; k++){
        for (int i = 1; i <= n - k; i++) {
            int j = i + k;
            if (a[i] == a[j] && d[i + 1][j - 1]) d[i][j] = true;
        }
    }
    int m; cin >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        cout << d[a][b] << '\n';
    }
}