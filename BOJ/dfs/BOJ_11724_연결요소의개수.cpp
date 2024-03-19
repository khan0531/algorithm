#include <bits/stdc++.h>

using namespace std;

int n, m;
int cnt;
vector<int> e[1005];
bool vis[1005];

void dfs(int cur) {
    vis[cur] = true;

    for (int nxt : e[cur]){
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        cnt++;
        dfs(i);
    }

    cout << cnt;
}
