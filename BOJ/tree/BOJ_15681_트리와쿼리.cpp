#include <bits/stdc++.h>

using namespace std;

int n, r, q;
vector<int> adj[100005];
int p[100005];
int node_cnt[100005];

void dfs(int cur){
    for (int nxt : adj[cur]) {
        if(p[cur] == nxt) continue;
        p[nxt] = cur;
        dfs(nxt);
        node_cnt[cur] += node_cnt[nxt];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> r >> q;

    int k = n - 1;
    int u, v;
    while (k--){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(node_cnt, node_cnt + n + 1, 1); //자기 자신 노드 한개 미리 넣어두기.
    dfs(r);
    
    int Q;
    while (q--){
        cin >> Q;
        cout << node_cnt[Q] <<'\n';
    }
}