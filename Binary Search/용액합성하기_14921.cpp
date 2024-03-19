#include <bits/stdc++.h>

using namespace std;

int a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans1 = 100000000;
    int ans2 = 100000000;
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(a, a + n, -a[i]) - a;
        if(idx < n && idx != i && abs(a[i] + a[idx]) < abs(ans1 + ans2)){
            ans1 = a[i];
            ans2 = a[idx];
        }
        if(idx + 1 < n && idx + 1 != i && abs(a[idx + 1] + a[i]) < abs(ans1 + ans2)){
            ans1 = a[i];
            ans2 = a[idx + 1];
        }
        if(idx - 1 >= 0 && idx - 1 != i && abs(a[idx - 1] + a[i]) < abs(ans1 + ans2)){
            ans1 = a[i];
            ans2 = a[idx - 1];
        }
    }
    cout << ans1 + ans2;
}