#include <bits/stdc++.h>

using namespace std;

const int ROOT = 1;
int unused = 2;
const int MAX = 10000 * 500 + 5;
int nxt[MAX][26];
bool chk[MAX];
int n, m, cnt;
// 5000000 * 26 * 4 Byte
// 5 * 26 * 4 MB

void insert(string& s) {
    int cur = ROOT;
    for (char c : s) {
        if (nxt[cur][c - 'a'] == 0) nxt[cur][c - 'a'] = unused++;
        cur = nxt[cur][c - 'a'];
    }
    chk[cur] = true;
}

bool find(string& s) {
    int cur = ROOT;
    for (char c : s){
        if (nxt[cur][c - 'a'] == 0) return false;
        cur = nxt[cur][c - 'a'];
    }
    return chk[cur];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    string s;
    while(n--) {
        cin >> s;
        insert(s);
    }
    while(m--) {
        cin >> s;
        if (find(s)) cnt++;
    }
    cout << cnt;
}
