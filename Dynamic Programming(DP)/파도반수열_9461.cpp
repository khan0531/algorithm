#include <bits/stdc++.h>

using namespace std;

long long p[110];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >>t;
    p[1] = 1;
    p[2] = 1;
    p[3] = 1;
    p[4] = 2;
    p[5] = 2;

    while(t--){
        int n; cin >>n;
        for (int i = 6; i <= n; i++) {
            p[i] = p[i - 1] + p[i - 5];
        }

        cout << p[n] << '\n';
    }
}