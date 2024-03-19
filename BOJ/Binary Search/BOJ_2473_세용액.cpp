#include <bits/stdc++.h>

using namespace std;

int a[5005];
vector<int> sum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long ans1 = 1'000'000'001;
    long long ans2 = 1'000'000'001;
    long long ans3 = 1'000'000'001;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long x = a[i] + a[j];
            int idx = lower_bound(a, a + n, -x) - a;
            if(idx < n && idx != i && idx != j && abs(a[idx] + x) < abs(ans1 + ans2 + ans3)){
                ans1 = a[idx];
                ans2 = a[i];
                ans3 = a[j];
            }
            if(idx + 1 < n && idx + 1 != i && idx + 1 != j && abs(a[idx + 1] + x) < abs(ans1 + ans2 + ans3)){
                ans1 = a[idx + 1];
                ans2 = a[i];
                ans3 = a[j];
            }
            if(idx - 1 >= 0 && idx - 1 != i && idx - 1 != j && abs(a[idx - 1] + x) < abs(ans1 + ans2 + ans3)){
                ans1 = a[idx - 1];
                ans2 = a[i];
                ans3 = a[j];
            }
        }
    }
    long long ans[3] = {ans1, ans2, ans3};
    sort(ans, ans + 3);
    for (int i = 0; i < 3; i++) {
        cout << ans[i] << ' ';
    }
}