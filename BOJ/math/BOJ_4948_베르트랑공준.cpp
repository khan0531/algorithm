#include <bits/stdc++.h>

using namespace std;

int N = 123456*2;
vector<bool> isPrime(N, true);

void prime(int n) {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i <= n; i++) {
        if (!isPrime[i]) continue;
        for (int j = i*i; j <=n; j+=i) {
            isPrime[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    prime(N);

    while(1){
        int n; cin >> n;
        if (n == 0) break;

        int cnt = 0;
        for (int i = n + 1; i <= 2*n; i++) {
            if (isPrime[i]) cnt++;
        }
        cout << cnt << '\n';
    }
}