#include <bits/stdc++.h>

using namespace std;

int d[2000005];

void manacher(string s, int n){
    int r = 0;
    int p = 0;
    for (int i = 0; i < n; i++) {
        if (r < i) d[i] = 0;
        else d[i] = min(r - i, d[2*p - i]);
        while(i - d[i] - 1 >= 0 && i + d[i] + 1 < n && s[i - d[i] - 1] == s[i + d[i] + 1]) d[i]++;
        if (r < i + d[i]){
            r = i + d[i];
            p = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    string s = "";
    s += "#";
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s += (a + '0');
        s += "#";
    }
    manacher(s, s.size());
    int m; cin >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        int aa = 2*a - 1;
        int bb = 2*b - 1;
        int c = (aa + bb)/2;
        cout << (c + d[c] >= bb ? "1\n" : "0\n");
        // if(c + d[c] >= bb) cout << 1 << '\n';
        // else cout << 0 << '\n';
    }
}