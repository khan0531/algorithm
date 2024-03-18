#include <bits/stdc++.h>

using namespace std;

int k, l;
vector<string> v;
unordered_map<string, int> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> l;
    for (int i = 0; i < l; i++) {
        string s;
        cin >> s;
        m[s]++;
        v.push_back(s);
    }
    int cnt = 0;
    for(auto c : v){
        if(cnt == k) break;
        if(m[c] != 1) m[c]--;
        else {
            cout << c <<'\n';
            cnt++;
        }
    }
}