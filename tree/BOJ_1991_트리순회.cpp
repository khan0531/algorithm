#include <bits/stdc++.h>

using namespace std;

int n;
int lc[30];
int rc[30];

// 전위 순회
void dfs1(int cur){
    char ans = cur + 'A' - 1;
    cout << ans;
    if (lc[cur] != 0) dfs1(lc[cur]);
    if (rc[cur] != 0) dfs1(rc[cur]);
}

//중위 순회
void dfs2(int cur){
    if (lc[cur] != 0) dfs2(lc[cur]);
    char ans = cur + 'A' - 1;
    cout << ans;
    if (rc[cur] != 0) dfs2(rc[cur]);
}

//후위 순회
void dfs3(int cur){
    if (lc[cur] != 0) dfs3(lc[cur]);
    if (rc[cur] != 0) dfs3(rc[cur]);
    char ans = cur + 'A' - 1;
    cout<< ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while(n--){
        char p, l, r;
        cin >> p >> l >> r;
        if (l != '.') lc[p - 'A' + 1] = l - 'A' + 1;
        if (r != '.') rc[p - 'A' + 1] = r - 'A' + 1;
    }
    dfs1(1);
    cout<<'\n';
    dfs2(1);
    cout<< '\n';
    dfs3(1);
}