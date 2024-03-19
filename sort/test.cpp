#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, string>& a, pair<int, string>& b) {
    if (a.first != b.first) return a.first < b.first;

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    pair<int, string> p[100];;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    stable_sort(p, p + n, [](const pair<int, string>& a, pair<int, string>& b) {
        if (a.first != b.first) return a.first < b.first;

        return false;
    });

    for (int i = 0; i < n; i++) {
        cout << p[i]. first << ' ' << p[i].second << '\n';
    }

    do {
    } while (next_permutation())
}