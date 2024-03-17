#include <bits/stdc++.h>

using namespace std;

using pa = pair<int, int>;
using tu = tuple<int, int, int>;

const int MAX = 0x7f7f7f7f;
vector<pa> adj[805];
int N, E;

int dijkstra(int start, int end) {
   int d[805];
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

   cin >> N >> E;
   while(E--) {
      int a, b, c; cin >> a >> b >> c;
      adj[a].push_back({b, c});
      adj[b].push_back({a, c});
   }

   int v1, v2; cin >> v1 >> v2;

   int a = dijkstra(1, v1);
   int b = dijkstra(v1, v2);
   int c = dijkstra(v2, N);
   int d = dijkstra(1, v2);
   int f = dijkstra(v1, N); 

   if (a == MAX || d == MAX || c == MAX || f == MAX || b == MAX) {
      cout << -1;
      return 0;
   }

   int len1 = a + b + c;
   int len2 = d + b + f;

   len1 < len2 ? cout << len1 : cout << len2;
}