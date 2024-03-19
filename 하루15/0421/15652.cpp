#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[10];
int ans[10];

void func (int k) {
    if (k == m + 1) {
       for (int i = 1; i <= m; i++) {
           cout << ans[i] <<' ';
       }
        cout <<'\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (ans[k - 1] > a[i]) continue;
        ans[k] = a[i];
        func(k + 1);
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    func(1);


}
