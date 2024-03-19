#include <bits/stdc++.h>

using namespace std;

int n;
int a[2005];
int cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        bool is_used = false;
        for (int j = 0; j < n; j++) {
            if(i == j) continue;
            int idx = lower_bound(a, a + n, a[i] - a[j]) - a;
            if(is_used) break;
            while(idx < n && a[idx] == a[i] - a[j]){
                    if(idx != i && idx != j) {
                        cnt++;
                        is_used = true;
                        break;
                    }
                idx++;
            }
        }
    }
    cout << cnt;
}