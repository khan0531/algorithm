#include <bits/stdc++.h>

using namespace std;

bool prime[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >>t;

    fill(prime, prime + 10000, true);
    prime[1] = false;
    for (int i = 2; i*i < 10001; i++) {
        if(!prime[i]) continue;
        for (int j = i*i; j < 10001; j+=i) {
            prime[j] = false;
        }
    }

    while(t--){
        int n; cin >> n;
        int ans1, ans2;

        for (int i = n/2; i >= 0; i--) {
            if(!prime[i] || !prime[n - i]) continue;
            ans1 = i;
            ans2 = n - i;
            break;
        }
        cout << ans1 << ' ' << ans2 << '\n';
    }
}