#include <bits/stdc++.h>

using namespace std;

string s;
vector<string> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;

    int sz = s.size();

    for (int i = 0; i < sz; i++) {
        string cur = {};
        for (int j = i; j < sz; j++) {
            cur += s[j];
        }
        v.push_back(cur);
    }

    sort(v.begin(), v.end());

    for(auto k : v) cout << k << '\n';
}