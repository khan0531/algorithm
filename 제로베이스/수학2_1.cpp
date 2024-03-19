#include <bits/stdc++.h>

using namespace std;

int n;
int d[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[0] = 1;
    d[1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i/2; j++) {
            d[i + 1] += d[j]*d[i-j];
        }
        d[i + 1] *= 2;
        if (i%2 == 0) d[i + 1] -= d[i/2]*d[i/2];
    }
    
    cout << d[n];
}
