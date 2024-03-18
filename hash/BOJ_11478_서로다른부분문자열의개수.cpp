#include <bits/stdc++.h>

using namespace std;

int ans;
string s;
unordered_map<string, int> m;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    for(int i = 0; i < s.size(); i ++){
        string ss = "";
        for (int j = i; j < s.size(); j++) {
            ss += s[j];
            m[ss]++;
        }
    }
    cout << m.size();
}