#include <bits/stdc++.h>

using namespace std;

int t;
long long d[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for (int i = 4; i < 1000001; i++) {
        d[i] = (d[i - 1] + d[i - 2] + d[i - 3])%1000000009;
    }
    while(t--){
        int n; cin >> n;
        cout << d[n] <<'\n';
    }
}