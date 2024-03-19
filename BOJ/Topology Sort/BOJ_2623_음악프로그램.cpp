#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1005];
vector<int> result;
int ind[1005];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int singer_cnt, singer_num, pre;
    while(m--) {
        cin >> singer_cnt;
        cin >> singer_num;
        pre = singer_num;
        for (int i = 1; i < singer_cnt; i++){
            cin >> singer_num;
            adj[pre].push_back(singer_num);
            ind[singer_num]++;
            pre = singer_num;
        }
    }
    
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        result.push_back(cur);
        q.pop();

        for (int nxt : adj[cur]){
            if (--ind[nxt] == 0) q.push(nxt); 
        }
    }
    if (result.size() != n) cout << 0;
    else {
        for (int ans : result) cout << ans << '\n';
    }
}