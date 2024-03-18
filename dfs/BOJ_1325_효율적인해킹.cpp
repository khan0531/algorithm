#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> e[10005];
vector<int> com;
bool vis[10005];
int cnt[10005];

void bfs(int x){
    queue<int> q;
    q.push(x);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int nxt : e[cur]){
            if(vis[nxt]) continue;
            vis[nxt] = true;
            q.push(nxt);
            cnt[x]++;
        }
    }
}

//재귀
int k = 0;
void dfs(int cur){
    vis[cur] = true;
    k++;
    for(int nxt : e[cur]){
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--){
        int v1, v2;
        cin >> v1 >> v2;
        e[v2].push_back(v1);
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        fill(vis, vis + n + 1, false);
        k = 0;
        dfs(i);
        cnt[i] = k;
        mx = max(k, mx);
    }
    for (int i = 1; i <= n; i++) {
        if(cnt[i] == mx) cout << i << ' ';
    }   
}
