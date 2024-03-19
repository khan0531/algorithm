#include <bits/stdc++.h>

using namespace std;

int n;
int k;
int d[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fill(d, d + n + 1, 100000000);
    for (int i = 0; i <= n; i++) {
        if(i == k*k) {
            d[i] = 1;
            k++;
        }
        else {
            int a = 1;
            while(a != k){
                d[i] = min(d[i], d[(k - a)*(k - a)] + d[i - (k - a)*(k - a)]);
                a++;
            }
        }
    }
    cout << d[n];
}