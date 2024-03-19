#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, c, cnt, ans;
int g[100005];
vector<tuple<int, int, int>> h;

int find(int x){
    if (g[x] == x) return x;

    return g[x] = find(g[x]);
}

bool is_same_group(int x, int y){
    x = find(x); y = find(y);

    if (x == y) return true;

    g[y] = x;

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while(m--){
        cin >> a >> b >> c;
        h.push_back({c, a, b});
    }
    sort(h.begin(), h.end());

    for (int i = 1; i <= n; i++) {
        g[i] = i;
    }

    for (auto cur : h){
        auto [z, x, y] = cur;
        if (is_same_group(x, y)) continue;
        ans += z;
        cnt++;
        if (cnt == n - 1){
            ans -= z;
            break;
        }
    }
    cout << ans;
}
