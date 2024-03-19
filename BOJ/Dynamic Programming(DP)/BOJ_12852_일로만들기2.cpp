#include <bits/stdc++.h>

using namespace std;

int d[1000005];
int cur[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >>n;

    d[1] = 0;
    cur[0] = 1;
    for (int i = 2; i <= n; i++) {
        d[i] = d[i - 1] + 1;
        cur[i] = i - 1;

        if(i%3 == 0 && d[i / 3] + 1 < d[i]) {
            d[i] = d[i / 3] + 1;
            cur[i] = i/3;
        }

        if(i%2 == 0 && d[i / 2] + 1 < d[i]) {
            d[i] = d[i / 2] + 1;
            cur[i] = i/2;
        }
    }
    cout << d[n] <<'\n';
    int k = n;
    for (int i = 0; i <= d[n]; i++) {
        cout << k << ' ';
        k = cur[k];
    }

}