#include <bits/stdc++.h>

using namespace std;

int n, s, sum, cnt;
int a[25];
int b[25];

void func(int k) {
    if (k == n) {
        if (sum == s) cnt++;
        return;
    }

    func(k + 1);
    sum += a[k];
    func(k + 1);
    sum -= a[k];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    func(0);
    
    if (s == 0) cout << cnt - 1;
    else cout << cnt;
}
