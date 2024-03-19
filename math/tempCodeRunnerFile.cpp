#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

//a^d mod n
ull power(ull a, ull d, ull n) {
    ull res =1;
    a %= n;
    while(d) {
        if (d%2 == 1) res = (res * a) % n;
        a = (a * a) % n;
        d /= 2;
    }
    return res;
}

bool millerRabin(ull n, ull a) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n%2 == 0) return false;
    if (a%n == 0) return true;

    ull x = n - 1;
    while (true) {
        ull tmp = power(a, x, n);
        if (tmp == n - 1) return true;
        if (x % 2 == 1) return (tmp == 1 || tmp == n - 1);
    }
    return false;
}

bool isPrime(ull n) {
    for (ull a : {2, 7, 61}) {
        if (!millerRabin(n, a)){
            return false;
        }
    }
    return true;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    

}