#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> child[1005];
vector<string> family;
string s[1005];
map<string, int> name;
int dis[1005];
int child_cnt[1005];
bool vis[1005];
int ind[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    sort(s + 1, s + n + 1);

    for (int i = 1; i <= n; i++) {
        name[s[i]] = i;
    }

    cin >> m;
    string a, b;
    while(m--){
        cin >> a >> b;
        child[name[b]].push_back(a);
        ind[name[a]]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (ind[i] != 0 || vis[i]) continue;
        family.push_back(s[i]);
        q.push(i);
        dis[i] = 0;
        int cur;

        while(!q.empty()){
            cur = q.front();
            vis[cur] = true;
            q.pop();

            for (string nxt : child[cur]) {
                if (--ind[name[nxt]] == 0) q.push(name[nxt]);
                dis[name[nxt]] = dis[cur] + 1;
            }
        }

    }

    cout << family.size() <<'\n';
    sort(family.begin(), family.end());
    for (string cur : family) cout << cur << ' ';
    cout << '\n';

    for (int i = 1; i <= n; i++) {
        sort(child[i].begin(), child[i].end());
        for (string cur : child[i]) {
            if (dis[name[cur]] - dis[i] == 1) child_cnt[i]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << s[i] << ' ' << child_cnt[i] <<' ';
        for (string cur : child[i]) {
            if (dis[name[cur]] - dis[i] != 1) continue;
            cout << cur << ' ';
        }
        cout << '\n';
    }
     
}
