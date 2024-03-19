#include <bits/stdc++.h>

using namespace std;

int n, a, b, c;
int lc[100005];
int rc[100005];
int depth[10005];
int cnt, r_cnt, ans;

void dfs(int cur){
    if (lc[cur] != 0){
        cnt++;
        dfs(lc[cur]);
        cnt++;
    }
    if (rc[cur] != 0){
        cnt++;
        dfs(rc[cur]);
        cnt++;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        if(b != -1) lc[a] = b;
        if(c != -1) rc[a] = c;
    }
    dfs(1);
    int cur = 1;
    while (rc[cur] != 0) {
        cur = rc[cur];
        r_cnt++;
    }
    cout << cnt - r_cnt;
}