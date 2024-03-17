#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using tu = tuple<ll, int, int>;

int V, E;
int g[10005];
priority_queue<tu, vector<tu>, greater<tu>> pq;

int find(int x) {
    if (g[x] == x) return x;
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

    cin >> V >> E;
    while(E--) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({c, a, b});
    }

    for (int i = 1; i <= V; i++) g[i] = i;

    int cnt = 0;
    int ans = 0;
    while(cnt != V - 1) {
        auto [dis, x, y] = pq.top();
        pq.pop();
        if (isSameGroup(x, y)) continue;
        ans += dis;
        cnt++;
        if (cnt == V) break;
    }
    cout << ans;
}
