#include <bits/stdc++.h>

using namespace std;

int n;
int a[15]; // 인구 수
int b[15]; // 인접한 구역들의 집합. 같은 값이면 같은 구역에 속한 것.
bool vis[15];
vector<int> adj[15];
vector<int> area[2];
int mn = 10000000;
bool is_divid;

void dfs(int cur) {
    vis[cur] = true;
    for (int nxt : adj[cur]) {
        if (vis[nxt]) continue;
        if (b[nxt] != b[cur]) continue;
        vis[nxt] = true;
        dfs(nxt);
    }
}

int sum(vector<int> v) {
    int s = 0;
    for (int i : v) s += a[i];
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        int k; cin >> k;

        while(k--){
            int a; cin >> a;
            adj[i].push_back(a);
            adj[a].push_back(i);
        }
    }

    for (int temp = 1; temp < (1 << n) - 1; temp++) {
        int brute = temp;

        for (int i = 0; i <= 1; i++) {
            area[i].clear();
        }

        for (int i = 1; i <= n; i++) {
            area[brute%2].push_back(i);
            b[i] = brute%2;
            brute /= 2;
        }

        // dfs를 돌고
        fill(vis, vis + n + 1, false);
        dfs(area[0][0]);
        dfs(area[1][0]);

        //방문 하지 않는 지점이 있다면 그 구역은 인접하지 않다는 뜻.
        is_divid = true;
        for (int i = 0; i <= 1; i++) {
            for (int j : area[i]) 
                if (!vis[j]) {
                    is_divid = false;
                    break;
                }
            if (!is_divid) break;
        }

        if (!is_divid) continue;
    
        int dif = abs(sum(area[0]) - sum(area[1]));
        mn = min(mn, dif);
    }
    if (mn != 10000000) cout << mn;
    else cout << -1;
}