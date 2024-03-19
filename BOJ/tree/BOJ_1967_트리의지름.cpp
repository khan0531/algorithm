#include <bits/stdc++.h>

using namespace std;

int n, par, child, dist;
vector<pair<int, int>> adj[10005]; // {v, d};
int p[10005];
int dis[10005];
int mx, a;
int ans;

void dfs (int cur) {
    for (auto nxt : adj[cur]){
        if (p[cur] == nxt.first) continue;
        p[nxt.first] = cur;
        dis[nxt.first] = dis[cur] + nxt.second;
        if (mx < dis[nxt.first]){
            mx = dis[nxt.first];
            a = nxt.first;
        }
        dfs(nxt.first);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> par >> child >> dist;
        adj[par].push_back({child, dist});
        adj[child].push_back({par, dist});
    }

    dfs(1);
    fill(p, p + n + 1, 0);
    fill(dis, dis + n + 1, 0);
    mx = 0;
    dfs(a);

    cout << mx;
}