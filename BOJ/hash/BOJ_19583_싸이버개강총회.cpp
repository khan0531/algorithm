#include <bits/stdc++.h>

using namespace std;

int ans;
string s, e, q;
unordered_map<string, int> st;
unordered_map<string, int> en;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s >> e >> q;
    int k = 17;
    while(true){
        string time, name;
        cin >> time >> name;
        if (cin.eof()) break;
        if(time <= s) st[name]++;
        if(time >= e && time <= q) en[name]++;
    }

    for(auto cur : st){
        if(en[cur.first] >= 1) ans++;
    }
    cout << ans;
}