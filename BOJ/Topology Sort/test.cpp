#include <bits/stdc++.h>

using namespace std;

vector<int> adj[32005];
int ind[32005];
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    int a, b;
    while(m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        ind[b]++;
    }
    
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int cur = q.front();
        cout << cur << ' ';
        q.pop();
        for (int nxt : adj[cur]) {
            if (--ind[nxt] == 0) q.push(nxt);
        }
    }
}
