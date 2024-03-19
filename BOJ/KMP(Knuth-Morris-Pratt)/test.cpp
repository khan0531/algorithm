#include <bits/stdc++.h>

using namespace std;

vector<int> failure(string& s) {
    vector<int> f(s.size());
    int j = 0;
    for (int i = 1; i < s.size(); i++) {
        while(j > 0 && s[i] != s[j]) j = f[j - 1];
        if (s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

void kmp(string& t, string& p) {
    vector<int> f = failure(p);

    int len = p.size();
    int cnt = 0;
    vector<int> ans;

    int j = 0;
    for (int i = 0; i < t.size(); i++) {
        while(j > 0 && t[i] != p[j]) j = f[j - 1];
        if (t[i] == p[j]) j++;
        if (j == p.size()) {
            cnt++;
            ans.push_back(i+2-len);
        }
    }
    cout << cnt << '\n';
    for (int i : ans) cout << i << ' ';
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string t; getline(cin, t);
    string p; getline(cin, p);
    kmp(t, p);
}
