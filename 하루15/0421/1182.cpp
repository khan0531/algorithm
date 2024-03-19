#include <bits/stdc++.h>

using namespace std;

int n, s, cnt, sum;
int a[25];
int ans[25];
bool is_used[25];

void func(int k, int m) {
    if (k == m) {
        sum = 0;
        for (int i = 0; i < m; i++) {
            sum += ans[i];
        }

        if (sum == s) {
            cnt++;
            for (int i = 0; i < k; i++) {
                cout << ans[i]<< ' ';
            }
            cout << '\n';
        }
        return;
    }

    for (int i = k; i < n; i++) {
        if (is_used[i]) continue;
        ans[k] = a[i];
        // is_used[i] = true;
        func (k + 1, m);
        // is_used[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        func(0, i);
    }
    cout << cnt;
}
