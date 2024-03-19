#include <bits/stdc++.h>

using namespace std;

int n, sum;
long long cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    vector<bool>is_prime(n + 1, true);
    vector<int>primes;
    is_prime[1] = false;
    for (int i = 2; i*i <= n; i++) {
        if(!is_prime[i]) continue;
        for (int j = i*i; j <= n; j += i) {
           is_prime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++) {
        if(!is_prime[i]) continue;
        primes.push_back(i);
    }
    int st = 0, en = 0;
    sum = 2;
    while(primes[en] <= n && primes[en] != 0){
        if(sum <= n){
            if(sum == n) cnt++;
            en++;
            sum += primes[en];
        }
        else {
            sum -= primes[st];
            st++;
        }
    }
    cout << cnt;
}