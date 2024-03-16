#include <bits/stdc++.h>

using namespace std;

int n;
int a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    stack<int> s[4];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        bool isclean = false;
        for (int j = 0; j < 4; j++) {
            if (s[j].empty() || a[i] > s[j].top()) {
                s[j].push(a[i]);
                isclean = true;
                break;
            }
        }

        if (!isclean) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
