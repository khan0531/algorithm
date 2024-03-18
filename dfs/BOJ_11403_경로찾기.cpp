#include <bits/stdc++.h>

using namespace std;

int n;
int board[105][105];
bool vis[105];
vector<int> e[105];

void dfs(int cur){
    for(int nxt : e[cur]){
        if(vis[nxt]) continue;
        vis[nxt] = true;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0) continue;
            e[i].push_back(j);
        }
    }
    for (int i = 0; i < n; i++) {
        fill(vis, vis + n, false);
        dfs(i);
        for (int j = 0; j < n; j++) {
            cout << vis[j] << ' ';
        }
        cout << '\n';
    }   
}