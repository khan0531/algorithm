#include <bits/stdc++.h>

using namespace std;

int a[100005];
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);  

    for (int i = 0; i < n; i++) {
        ans = max(ans, (n - i) * a[i]);
    }
    cout << ans;    
}