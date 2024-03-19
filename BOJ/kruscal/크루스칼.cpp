#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, cnt;
int g[25];
vector<tuple<int, int, int>> v;
ll ans;

int find(int x) {
    if (g[x] == x) return x;

    return g[x] = find(g[x]);
}

bool is_same_group(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return true;

    g[x] = y;

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        g[i] = i;
    }

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v.push_back({c, a, b});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++) {
        auto [z, x, y] = v[i];
        if (is_same_group(x, y)) continue;
        ans += z;
        cnt++;
        if (cnt == n - 1) break;
    }
    
}
