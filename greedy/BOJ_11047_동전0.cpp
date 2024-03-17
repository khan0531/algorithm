#include <bits/stdc++.h>

using namespace std;

long long d[10000005];
long long a[15];
long long ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    long long k;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

   for (int i = n - 1; i >= 0; i--) {
       if(k < a[i]) continue;
       while(k > a[i]){
        ans += k/a[i];
        k %= a[i];
        if(k == 0) break;
       }
   }
   cout << ans;
}