#include <bits/stdc++.h>

using namespace std;

int n, r, q;
vector<int> adj[100005];
int child[100005];
int p[100005];

void dfs(int cur){
    for (int nxt : adj[cur]){
        if (p[cur] == nxt) continue;
        p[nxt] = cur;
        dfs(nxt);
        child[cur] += child[nxt];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> q;

    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(child, child + n + 1, 1);
    dfs(r);

    int Q;
    while(q--){
        cin >> Q;
        cout << child[Q] << '\n';
    }
}
