#include <bits/stdc++.h>

using namespace std;

int n, m, true_cnt;
bool know_true[55];
bool party_know;
bool vis[55];
vector<int> party[55];
vector<int> adj[55];
int ans;

void dfs (int cur) {
    for(int nxt : adj[cur]) {
        if (vis[nxt]) continue;
        vis[nxt] = true;
        if (know_true[cur]) know_true[nxt] = true;
        dfs(nxt);
        if (know_true[nxt]) know_true[cur] = true;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    cin >> true_cnt;

    int a;
    while (true_cnt--) {
        cin >> a;
        know_true[a] = true;
    }
   
    int party_num, people_num;
    for (int i = 1; i <= m; i++) {
        cin >> party_num;
        cin >> people_num;
        party[i].push_back(people_num);

        int pre = people_num;
        while (--party_num){
            cin >> people_num;
            party[i].push_back(people_num);
            adj[pre].push_back(people_num);
            adj[people_num].push_back(pre);
            pre = people_num;
        }
    }

    for (int i = 1; i <= n; i++) {
        fill(vis, vis + n + 1, false);
        dfs(i);
    }

    bool p;
    for (int i = 1; i <= m; i++) {
        p = true;
        for (int cur : party[i]){
            if (know_true[cur]) {
                p = false;
                break;
            }
        }
        if (!p) continue;
        ans++;
    }
    cout << ans;
}