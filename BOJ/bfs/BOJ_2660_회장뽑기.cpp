#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> e[55];
int dis[55];
int f[55];
int mn = 100000;
vector<int> cand;

void bfs(int x){
    int mx = 0;
    queue<int> q;
    q.push(x);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for (int nxt : e[cur]){
            if(dis[nxt] != -1) continue;
            dis[nxt] = dis[cur] + 1;
            mx = max(dis[nxt], mx);
            q.push(nxt);
        }
    }
    f[x] = mx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while(true){
        int v1, v2;
        cin >> v1 >> v2;
        if(v1 == -1 && v2 == -1) break;
        e[v1].push_back(v2);
        e[v2].push_back(v1);
    }
    for (int i = 1; i <= n; i++) {
        fill(dis + 1, dis + n + 1, -1);
        dis[i] = 0;
        bfs(i);
        mn = min(mn, f[i]);
    }
    for (int i = 1; i <= n; i++) {
        if(f[i] == mn) cand.push_back(i);
    }
    cout << mn << ' ' << cand.size() <<'\n';
    for(int i : cand) cout << i << ' ';
}
