#include <bits/stdc++.h>

using namespace std;

int n, m, v;
vector<int> e[1005];
bool vis[1005];

//비재귀 dfs
void dfs(){
    stack<int> s;
    s.push(v);

    while(!s.empty()){
        int cur = s.top();
        s.pop();
        if(vis[cur]) continue;
        cout << cur << ' ';
        vis[cur] = true;
        for(int i = e[cur].size() - 1; i >= 0; i --){
            if(vis[e[cur][i]]) continue;
            s.push(e[cur][i]);
        }
    }
}

//재귀
void dfs1(int cur){
    vis[cur] = true;
    cout << cur << ' ';

    for(int nxt : e[cur]){
        if (vis[nxt]) continue;
        dfs1(nxt);
    }
}

void bfs(){
    vis[v] = true;
    queue<int> q;
    q.push(v);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for(int nxt : e[cur]){
            if(vis[nxt]) continue;
            vis[nxt] = true;
            q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> v;
    while(m--){
        int v1, v2;
        cin >> v1 >> v2;
        e[v1].push_back(v2);
        e[v2].push_back(v1);        
    }
    for(int i = 1; i <= n; i++){
        sort(e[i].begin(), e[i].end());
    }
    dfs();
    fill(vis, vis + n + 1, false);
    cout << '\n';
    bfs();
}
