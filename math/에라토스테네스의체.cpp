#include <bits/stdc++.h>

using namespace std;

vector<int> primes(int n) {
    vector<int> prime;
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i <= n; i++) {
        if (!isPrime[i]) continue;
        for (int j = i*i; j <= n; j+=i) {
            isPrime[j] = false;
        }
    }

    for (int i = 2; i <= n; i++) 
        if (isPrime[i]) prime.push_back(i);
    
    return prime;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    
    for (int i : primes(n)) cout << i << ' ';
}