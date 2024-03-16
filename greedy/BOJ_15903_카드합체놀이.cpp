#include <bits/stdc++.h>

using namespace std;

int n, m;
long long ans;
long long a[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while(m--){
        sort(a, a + n);
        long long two_sum = a[0] + a[1];
        a[0] = two_sum;
        a[1] = two_sum;
    }
    for (int i = 0; i < n; i++) {
        ans += a[i];
    }
    cout << ans;
}