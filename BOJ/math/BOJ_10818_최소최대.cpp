#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << *min_element(a, a + n) << ' '<< *max_element(a, a + n);
}
