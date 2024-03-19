#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pa = pair<int, ll>;
using tu = tuple<ll, int, int>;

const ll MAX = 0x7f7f7f7f7f7f;
vector<pa> adj[100005];
priority_queue<tu, vector<tu>, greater<tu>> pq;
ll d[100005];

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

   int N, M; cin >> N >> M;
   int K; cin >> K;

   while(M--) {
      int u, v, c; cin >> u >> v >> c;
      adj[v].push_back({u, c});
   }

   fill(d, d + N + 1, MAX);

   while(K--) {
      int x; cin >> x;
      d[x] = 0;
      pq.push({0, x, x});
   }

   while(!pq.empty()) {
      auto [dis, st, en] = pq.top();
      pq.pop();
      if (dis != d[en]) continue;
      for (auto cur : adj[en]) {
         if (d[cur.first] <= dis + cur.second) continue;
         d[cur.first] = dis + cur.second;
         pq.push({d[cur.first], en, cur.first});
      }
   }

   ll mx = 0;
   int idx = 0;
   for (int i = 1; i <= N; i++) {
      if (d[i] > mx) {
         mx = d[i];
         idx = i;
      }
   }
   cout << idx << '\n' << mx;
}