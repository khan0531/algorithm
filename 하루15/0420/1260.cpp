#include <bits/stdc++.h>

using namespace std;

int n, m, v;
vector<int> adj[1005];
bool vis[1005];

void bfs (int x){
    queue<int> q;
    vis[x] = true;
    q.push(x);
    
    while(!q.empty()){
        int cur = q.front();
        cout << cur << ' ';
        q.pop();

        for (int nxt : adj[cur]) {
            if (vis[nxt]) continue;
            vis[nxt] = true;
            q.push(nxt);
        }
    }
}

void dfs(int cur) {
    cout << cur << ' ';
    vis[cur] = true;
    for (int nxt : adj[cur]) {
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> v;
    int a, b;
    while (m--){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(v);
    fill(vis, vis + n + 1, false);
    cout << '\n';
    bfs(v);
}
