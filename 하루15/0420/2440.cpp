#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while(n--) {
        for (int i = 0; i <= n; i++) {
            cout << '*';
        }
        cout <<'\n';
    }
}
