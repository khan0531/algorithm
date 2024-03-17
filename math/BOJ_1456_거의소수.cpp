#include <bits/stdc++.h>

using namespace std;

vector<int> seive(int n) {
    vector<int> primes;
    vector<bool> is_prime(n + 1, true);

    is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (!is_prime[i]) continue;

        for (int j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) primes.push_back(i);
    }

    return primes;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long a, b; cin >> a >>b;
    int ans = 0;

    vector<int>primes = seive(10000000);

    for(int prime : primes){
        long long cur = prime;
        while(cur <= b/prime){
            if(cur*prime >= a) ans++;
            cur *= prime;
        }
    }
    cout << ans;
}