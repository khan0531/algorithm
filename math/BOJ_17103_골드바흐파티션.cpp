#include <bits/stdc++.h>

using namespace std;

bool is_prime[1000007];
vector<int> primes;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    fill(is_prime, is_prime + 1000005, true);
    is_prime[1] = false;
    for (long long i = 2; i*i <= 1000005; i++) {
        if(!is_prime[i]) continue;
        
        for (long long j = i*i; j <= 1000005; j+=i) {
            is_prime[j] = false;
        }

    }
    for (long long i = 2; i <= 1000005; i++) {
        if(is_prime[i]) primes.push_back(i);
    }
    
    while(t--){
        int n; cin >> n;
        int cnt = 0;

        for(int prime : primes){
            if(prime > n/2) break;
            if(is_prime[n - prime]){
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}