#include <bits/stdc++.h>

using namespace std;

int n, m;
unordered_map<string, string> g;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(n--){
        string team;
        cin >> team;
        int a; cin >> a;
        while(a--){
            string member;
            cin >> member;
            g[member] = team;
        }
    }
    while(m--){
        string s; cin >> s;
        int a; cin >> a;
        if(a) cout << g[s] << '\n';
        else {
            vector<string> ans;
            for(auto cur : g){
                if(cur.second == s) ans.push_back(cur.first);
            }
            sort(ans.begin(), ans.end());
            for(auto c : ans) cout << c << '\n'; 
        }
    }
}