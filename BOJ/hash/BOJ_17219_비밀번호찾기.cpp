#include <bits/stdc++.h>

using namespace std;

int n, m;
unordered_map<string, string> p;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s, ss;
        cin >> s >> ss;
        p[s] = ss;
    }
    while(m--){
        string s;
        cin >> s;
        cout << p[s] <<'\n';
    }
}