#include <bits/stdc++.h>

using namespace std;

int n, cnt;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int a, b;
   for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({b, a});
    }
    sort(v.begin(), v.end());

    auto pre = v[0];
    cnt++;
    for (int i = 1; i < n; i++){
        if (v[i].second < pre.first) continue;
        pre = v[i];
        cnt++;
    }
    cout << cnt;
}
