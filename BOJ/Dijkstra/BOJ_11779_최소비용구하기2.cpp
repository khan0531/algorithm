#include <bits/stdc++.h>

using namespace std;

using pa = pair<int, int>;
using tu = tuple<int, int, int>;

const int MAX = 0x7f7f7f7f;
vector<pa> adj[1005];
priority_queue<tu, vector<tu>, greater<tu>> pq;
int d[1005];
int pre[1005];

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

   int N, M; cin >> N >> M;

   while(M--) {
      int st, en, v; cin >> st >> en >> v;
      adj[st].push_back({en, v});
   }

   int start, end; cin >> start >> end;

   fill(d, d + N + 1, MAX);
   d[start] = 0;
   pq.push({0, start, start});

   while(!pq.empty()) {
      auto [dis, st, en] = pq.top();
      pq.pop();
      if (dis != d[en]) continue;
      pre[en] = st;
      for (auto cur : adj[en]) {
         if (d[cur.first] <= cur.second + d[en]) continue;
         d[cur.first] = cur.second + d[en];
         pq.push({d[cur.first], en, cur.first});
      }
   }
   vector<int> city;

   int idx = end;
   while (idx != start) {
      city.push_back(idx);
      idx = pre[idx];
   }
   city.push_back(start);
   reverse(city.begin(), city.end());
   cout << d[end]<< '\n';
   cout << city.size() << '\n';
   for (int i : city) cout << i << ' ';
}