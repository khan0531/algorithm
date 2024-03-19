#include <bits/stdc++.h>

using namespace std;

using pa = pair<int, int>;
using tu = tuple<int, int, int>;

const int MAX = 0x7f7f7f7f;
vector<pa> adj[20005];
priority_queue<tu, vector<tu>, greater<tu>> pq;
int d[20005];

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

   int V, E; cin >> V >> E;
   int start; cin >> start;

   while(E--) {
      int st, en, v; cin >> st >> en >> v;
      adj[st].push_back({en, v});
   }

   fill(d, d + V + 1, MAX);
   d[start] = 0;

   pq.push({0, start, start});
   while(!pq.empty()) {
      auto [dis, st, en] = pq.top();
      pq.pop();
      if (dis != d[en]) continue;
      for (auto cur : adj[en]) {
         if(d[cur.first] <= cur.second + dis) continue;
         d[cur.first] = cur.second + dis;
         pq.push({d[cur.first], en, cur.first});
      }
   }
   for (int i = 1; i <= V; i++) {
      d[i] == MAX ? cout << "INF" << '\n' : cout << d[i] << '\n';
   }
}