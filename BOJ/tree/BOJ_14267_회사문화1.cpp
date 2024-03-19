#include <bits/stdc++.h>

using namespace std;

int n, m, num, a, b;
vector<int> adj[100005];
int depth[100005];

void dfs (int cur) {
    for (int nxt : adj[cur]) {
        depth[nxt] += depth[cur];
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> num;
        if (num == -1) continue;
        adj[num].push_back(i);
    }
    
    while (m--) {
        cin >> a >> b;
        depth[a] += b;
    }

    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << depth[i] << ' ';
    }
}
