#include <bits/stdc++.h>

using namespace std;

int n, w, ans, cnt;
bool vis[3005];
vector<pair<int, int>> adj[3005];
priority_queue<tuple<int, int, int>, 
                vector<tuple<int, int, int>>,
                greater<tuple<int, int, int>>> q;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> w;
        q.push({w, i, i});
    }
    
    int p;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> p;
            adj[i].push_back({j, p});
        }
    }

    while(cnt < n) {
        auto [z, x, y] = q.top();
        q.pop();
        if (vis[y]) continue;
        vis[y] = true;
        ans += z;
        cnt++;
        for (auto nxt : adj[y]) q.push({nxt.second, y, nxt.first});
    }

    cout << ans;
}
