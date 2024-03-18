#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;
vector<int> e[505];
int dis[505];

void bfs(){
    queue<int> q;
    q.push(1);
    
    while(!q.empty()){
        int cur = q.front();
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

    cin >> n;
    cin >> m;
    while(m--){
        int v1, v2;
        cin >> v1 >> v2;
        e[v1].push_back(v2);
        e[v2].push_back(v1);
    }
    fill(dis, dis + n + 1, -1);
    dis[1] = 0;
    bfs();
    for (int i = 1; i <= n; i++) {
        if(dis[i] > 0 && dis[i] <= 2) cnt++;
    }
    cout << cnt;
}
