#include <bits/stdc++.h>

using namespace std;

using tu = tuple<int, int, int>;
int n, ans, cnt;
int g[305];
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

    int w;
    for (int i = 1; i <= n; i++) {
        cin >> w;
        pq.push({w, 0, i});
    }

    for (int i = 1; i <= n; i++) {
        g[i] = i;
        for (int j = 1; j <= n; j++) {
            cin >> w;
            if (i == j) continue;
            pq.push({w, i, j});
        }
    }

    while(cnt != n) {
        auto [dis, x, y] = pq.top();
        pq.pop();
        if (isSameGroup(x, y)) continue;
        ans += dis;
        cnt++;
    }

    cout << ans;
}