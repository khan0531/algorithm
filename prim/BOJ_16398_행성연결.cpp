#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, cnt;
ll ans;
bool vis[1005];
vector<pair<int, int>> adj[1005];
priority_queue<pair<int, int>,
                vector<pair<int, int>>,
                greater<pair<int, int>>> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c;
            if (i == j) continue;
            adj[i].push_back({j, c});
        }
    }

    for(auto cur : adj[1]) q.push({cur.second, cur.first});
    vis[1] = true;
    cnt++;

    while(cnt < n){
        auto [x, y] = q.top();
        q.pop();
        if (vis[y]) continue;
        vis[y] = true;
        cnt++;
        ans += x;
        for (auto cur : adj[y]) q.push({cur.second, cur.first});
    }
    cout << ans;
}
