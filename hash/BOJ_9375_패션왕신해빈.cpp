#include <bits/stdc++.h>

using namespace std;

int m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m;
    while(m--){
        unordered_map<string, int> cl;
        int n; cin >> n;
        int cnt = 1;
        while(n--){
            string s, ss;
            cin >> s >> ss;
            cl[ss]++;
        }
        for(auto cur : cl){
            cnt *= (cur.second + 1);
        }
        cout << cnt - 1 << '\n';
    }
    
}