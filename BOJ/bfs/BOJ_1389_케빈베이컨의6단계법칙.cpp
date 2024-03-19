#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> e[105];
int dis[105];
int kb[105];
int mn = 1000000;
int ans;

void bfs(int x){
    queue<int> q;
    q.push(x);
    
    while(!q.empty()){
        int cur = q.front();
        kb[x] += dis[cur];
        q.pop();

        for(int nxt : e[cur]){
            if(dis[nxt] != -1) continue;
            dis[nxt] = dis[cur] + 1;
            q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while(m--){
        int v1, v2;
        cin >> v1 >> v2;
        e[v1].push_back(v2);
        e[v2].push_back(v1);
    }

    for (int i = 1; i <= n; i++) {
        fill(dis, dis + n + 1, -1);
        dis[i] = 0;
        bfs(i);
        if(kb[i] < mn){
            mn = kb[i];
            ans = i;
        }
    }
    cout << ans;
}
