#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
vector<int> adj[105]; // 자식들은 부모보다 무겁다.
vector<int> adj2[105];
bool vis[105];
bool vis2[105];
int cnt, cnt2;
int ans;

//자기 자신보다 무거운 갯수 찾기
void dfs (int cur) {
    for (int nxt : adj[cur]) {
        if (vis[nxt]) continue;
        vis[nxt] = true;
        dfs(nxt);
        cnt++;
    }
}

//자기 자신보다 가벼운 갯수 찾기
void dfs2 (int cur) {
    for (int nxt : adj2[cur]) {
        if(vis2[nxt]) continue;
        vis2[nxt] = true;
        dfs2(nxt);
        cnt2++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while (m--) {
        cin >> a >> b;
        adj[b].push_back(a); //b 보다 무거운 자식들 넣어두기.
        adj2[a].push_back(b); // a보다 가벼운거 넣어두기.
    }

    int N = (n+1)/2;
    for (int i = 1; i <= n; i++) {
        cnt = 0;
        cnt2 = 0;
        fill(vis, vis + n + 1, false);
        fill(vis2, vis2 + n + 1, false);
        dfs(i);
        dfs2(i);
        if (cnt  >= N || cnt2 >= N) ans++;
    }
    cout << ans;
}