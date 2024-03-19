#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using tu = tuple<ll, int, int>;

int n, cnt;
ll ans;
int g[1005];
priority_queue<tu, vector<tu>, greater<tu>> pq;

int find(int x) {
    if (x == g[x]) return x;
    return g[x] = find(g[x]);
}

bool isSameGroup(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return true;
    g[x] = y;

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        g[i] = i;
        for (int j = 0; j < n; j++) {
            int p; cin >> p;
            if (i == j) continue;
            pq.push({p, i, j});
        }
    }

    while(cnt != n-1) {
        auto [dis, x, y] = pq.top();
        pq.pop();
        if (isSameGroup(x, y)) continue;
        ans += dis;
        cnt++;
    }
    cout << ans;
}