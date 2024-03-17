#include <bits/stdc++.h>

using namespace std;
bool isprime[1000005];

void printPrime(int m, int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i*i <= n; i++) {
        if (!isPrime[i]) continue;
        for (int j = i*i; j <= n; j+=i) {
            isPrime[j] = false;
        }
    }
    for (int i = m; i <= n; i++)
    if (isPrime[i]) cout << i << '\n';

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m, n; cin >> m >> n;
    printPrime(m,n);
}