#include <bits/stdc++.h>

using namespace std;

int d[200'005];
int ans;
void manacher(string s){
    int n = s.size();
    string tmp = "#";
    for (int i = 0; i < n; i++) {
        tmp += s[i];
        tmp += "#";
    }

    int sz = tmp.size();

    int r = 0;
    int p = 0;
    for (int i = 0; i < sz; i++) {
        if(r < i) d[i] = 0;
        else d[i] = min(r - i, d[2*p - i]);
        while(i - d[i] - 1 >= 0 && i + d[i] + 1 < sz && tmp[i - d[i] - 1] == tmp[i + d[i] + 1]) d[i]++;
        if(r < i + d[i]){
            r = i + d[i];
            p = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s = "";
    cin >> s;
    int sz = s.size();
    manacher(s);
    for (int i = 0; i < 2*sz + 1; i++) {
        ans = max(ans, d[i]);
    }
    cout << ans;
}