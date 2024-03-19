#include <bits/stdc++.h>

using namespace std;

int n, m;
bool vis[100'005];
vector<int> adj[100'005];

int k;
void dfs(int cur) {
    vis[cur] = true;
    k++;

    for (int nxt : adj[cur]) {
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int a, b;
    while(m--) {
        cin >> a >> b;
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        fill (vis, vis + n + 1, false);
        k = 0;
        dfs(i);
    }
}