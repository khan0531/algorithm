#include <bits/stdc++.h>

using namespace std;

vector<int> adj[505];
int p[505];
int depth[505];
bool is_tree;
int case_num;

void dfs(int cur){
    for (int nxt : adj[cur]){
        if (p[cur] == nxt) continue;
        if (depth[nxt] != 0) {
            is_tree = false;
            return;
        }
        p[nxt] = cur;
        depth[nxt] = depth[cur] + 1;
        dfs(nxt);
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    while (true){
        cin >> n >> m;
        if (n ==0 && m == 0) break;

        case_num++;
        int cnt = 0;

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }

        int v1, v2;
        while(m--) {
            cin >> v1 >> v2;
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }

        fill(p, p + n + 1, 0);
        fill(depth, depth + n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (depth[i] != 0) continue;
            is_tree = true;
            dfs(i);
            if (is_tree) cnt++;
        }

        if (cnt == 0) cout << "Case " << case_num << ": " << "No trees." << '\n';
        else {
            if (cnt == 1) cout << "Case " << case_num << ": " << "There is one tree." << '\n';
            else cout << "Case " << case_num << ": " << "A forest of "<< cnt << " trees."<<'\n';
        }
    }
}
