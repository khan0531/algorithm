#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> p[100005];
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p[i].second >> p[i].first;
    }

    sort(p, p+n);
    queue<pair<long long, long long>>q;
    q.push(p[0]);
    ans++;
    for (int i = 1; i < n; i++) {
        auto cur = q.front();
        if (cur.first > p[i].second) continue;
        q.pop();
        q.push(p[i]);
        ans++;
    }
    cout << ans;
}