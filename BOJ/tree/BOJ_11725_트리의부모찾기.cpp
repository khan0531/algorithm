#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> adj[100005];
int p[100005];

void dfs(int cur) {
    for(int nxt : adj[cur]){
        if(p[cur] == nxt) continue;
        p[nxt] = cur;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int k = n - 1;
    while (k--) {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    dfs(1);
    for (int i = 2; i <= n; i++) {
        cout << p[i] << '\n';
    }
}
