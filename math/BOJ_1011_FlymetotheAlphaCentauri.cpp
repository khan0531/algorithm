#include <bits/stdc++.h>

using namespace std;

long long d[20000000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    d[1] = 1;
    for (long long i = 2; i <= 1 << 16; i++) {
        long long n = i/2;
        if(i % 2 == 0){
            d[i] = n*n + n; //n(n + 1)
        }
        if(i % 2 == 1){
            d[i] = n*n + 2*n + 1; // (n + 1)(n + 1)
        }
    }

    while(t--){
        long long x, y; 
        cin >> x >> y;
        long long n = y - x;
        
        for (long long i = 1; i <= 1048576; i++) {
            if(d[i - 1] < n && n <= d[i]){
                cout << i << '\n';
                break;
            }
        }
    }
}
