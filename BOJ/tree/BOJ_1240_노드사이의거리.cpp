#include <bits/stdc++.h>

using namespace std;

using pa = pair<int, int>;

int n, m, st, en;
vector<pa> adj[1005];
int depth[1005];
int p[1005];

void dfs(int cur) {
    for (auto nxt : adj[cur]) {
        p[nxt.first] = cur;
        depth[nxt.first] = depth[cur] + nxt.second;
        if (nxt.first == en) return;
        dfs(nxt.first);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int i, j, l;
    int k = n - 1;
    while (k--){
        cin >> i >> j >> l;
        adj[i].push_back({j, l});
        adj[j].push_back({i, l});
    }

    while (m--){
        cin >> st >> en;
        fill(p, p + n + 1, 0);
        fill(depth, depth + n + 1, 0);
        dfs(st);
        cout << depth[en] << '\n';
    }
}