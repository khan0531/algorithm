#include <bits/stdc++.h>

using namespace std;

int n, m, u, v;
vector<int> adj[100005];
int p[100005];
bool vis[100005];
int cnt;

void dfs(int cur) {
    for (int nxt : adj[cur]) {
        if(p[cur] == nxt || vis[nxt]) continue;
        p[nxt] = cur;
        vis[nxt] = true;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        dfs(i);
        cnt++;
    }

    cout << cnt - 1 + m + cnt - 1 - (n - 1);
}