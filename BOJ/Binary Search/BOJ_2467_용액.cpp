#include <bits/stdc++.h>

using namespace std;

int n;  
int a[100'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans1 = 1'000'000'000;
    int ans2 = 1'000'000'000;

    for (int i = 0; i < n; i++) {   
        int idx = lower_bound(a, a + n, -a[i]) - a;
        if(idx + 1 < n && i != idx + 1 && abs(a[i] + a[idx + 1]) < abs(ans1 + ans2)){
            ans1 = a[i];
            ans2 = a[idx + 1];
        }
        if(idx < n && i != idx && abs(a[idx] + a[i]) < abs(ans1 + ans2)){
            ans1 = a[i];
            ans2 = a[idx];
        }
        if(idx - 1 >= 0 && i != idx - 1 && abs(a[idx - 1] + a[i]) < abs(ans1 + ans2)){
            ans1 = a[i];
            ans2 = a[idx - 1];
        }
    }
    if(ans1 > ans2) swap(ans1, ans2);
    cout << ans1 << ' ' << ans2;
}