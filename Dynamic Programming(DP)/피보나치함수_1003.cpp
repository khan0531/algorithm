#include <bits/stdc++.h>

using namespace std;

int d[45];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    d[0] = 1;
    d[1] = 1;
    d[2] = 1;

    while(t--){
        int n; cin >> n;
        if (n == 0) {
            cout << 1 << ' ' << 0 <<'\n';
            continue;
        }
        if (n == 1) {
            cout << 0 << ' ' << 1 <<'\n';
            continue;
        }
        for (int i = 3; i <= n; i++) {
            d[i] = d[i - 1]+ d[i - 2];
        }
        
        cout << d[n - 1] << ' ' << d[n] <<'\n';
    }
}