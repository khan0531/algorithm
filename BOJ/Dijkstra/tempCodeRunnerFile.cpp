#include <bits/stdc++.h>

using namespace std;

using pa = pair<int, int>;
using tu = tuple<int, int, int>;

const int MAX = 0x7f7f7f7f;
vector<pa> adj[1005];
priority_queue<tu, vector<tu>, greater<tu>> pq;
int N, M, X;

int dijkstra(int start, int end) {
   int d[1005];
   fill(d, d+N+1, MAX);
   d[start] = 0;
   priority_queue<tu, vector<tu>, greater<tu>> pq;
   pq.push({0, start, start});

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
   return d[end];
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> N >> M >> X;

   while(M--) {
      int a, b, c; cin >> a >> b >> c;
      adj[a].push_back({b, c});
   }

   int mx = 0;
   for (int i = 1; i <= N; i++) {
      if (i == X) continue;
      int dis = dijkstra(i, X) + dijkstra(X, i);
      if (mx < dis) {
         mx = dis;
      }
   }

   cout << mx;
}