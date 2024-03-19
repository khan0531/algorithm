#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;
vector<int> e[105];
bool vis[105];

void dfs(int cur){
    for(int nxt : e[cur]){
        if(vis[nxt]) continue;
        vis[nxt] = true;
        dfs(nxt);
        cnt++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> m;
    while(m--){
        int v1, v2;
        cin >> v1 >> v2;
        e[v1].push_back(v2);
        e[v2].push_back(v1);
    }
    vis[1] = true;
    dfs(1);
    cout << cnt;
}
