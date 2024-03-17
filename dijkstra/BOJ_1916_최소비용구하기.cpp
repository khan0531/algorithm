#include <bits/stdc++.h>

using namespace std;

using pa = pair<int, int>;
using tu = tuple<int, int, int>;

const int MAX = 0x3f3f3f3f; 
vector<pa> adj[1005];
int d[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
   int N, M; cin >> N >> M;
   while(M--) {
      int st, en, v;
      cin >> st >> en >> v;

      adj[st].push_back({en, v});
   }

   int st, en; cin >> st >> en;

   fill(d, d + N + 1, MAX);

   priority_queue<tu, vector<tu>, greater<tu>> pq;

   pq.push({0, st, st});
   d[st] = 0;

   while (!pq.empty()) {
      auto [z, x, y] = pq.top();
      pq.pop();
      if (z != d[y]) continue;
      for (auto cur : adj[y]) {
         if (cur.second + z >= d[cur.first]) continue;
         d[cur.first] = cur.second + z;
         pq.push({d[cur.first], y, cur.first});
      }
   }

   cout << d[en];
}
