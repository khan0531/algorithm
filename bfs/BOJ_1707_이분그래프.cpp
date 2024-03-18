#include <bits/stdc++.h>

using namespace std;

string ans;
vector<int> e[20005];
int dis[20005];
void bfs(int x){
    queue<int> q;
    q.push(x);

    while (!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int nxt : e[cur]){
            if(dis[nxt] != -1){
                if(dis[nxt] == dis[cur]) {
                    ans = "NO";
                    return;
                }
                else continue;
            }
            dis[nxt] = dis[cur] + 1;
            q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k; cin >> k;
    while (k--){
        int V, E;
        cin >> V >> E;

        for (int i = 1; i <= V; i++) {
            e[i].clear();
        }

        while (E--){
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        ans = "YES";
        fill(dis, dis + V + 1, -1);
        for(int i = 1; i <= V; i++){
            if(dis[i] != -1) continue;
            dis[i] = 0;
            bfs(i);
        }
        cout << ans << '\n';
    }
}