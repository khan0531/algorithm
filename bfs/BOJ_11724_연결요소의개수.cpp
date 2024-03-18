#include <bits/stdc++.h>

using namespace std;

int n, m;
int cnt;
vector<int> e[1005];
bool vis[1005];

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

        queue<int> q;

        cnt++;
        q.push(i);
        vis[i] = true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for (int j : e[cur]){
                if (vis[j]) continue;

                q.push(j);
                vis[j] = true;
            }
        }
    }

    cout << cnt;
}
