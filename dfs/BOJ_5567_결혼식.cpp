#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;
vector<int> adj[505];
bool vis[505];

void dfs(int cur, int dis) {
    vis[cur] = true;
    if (dis == 2) return;
    for (int nxt : adj[cur]) {
        if (!vis[nxt]) {
            cnt++;
        }
        dfs(nxt, dis + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> m;
    while(m--){
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    dfs(1, 0);
    
    cout << cnt;
}
