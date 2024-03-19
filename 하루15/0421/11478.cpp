#include <bits/stdc++.h>

using namespace std;

string s;
map<string, int> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    
    int len = s.length();
    for (int i = 0; i < len; i++) {
        string ss = "";
        for (int j = i; j < len; j++) {
            ss += s[j];
            m[ss]++;
        }
    }
    cout << m.size();
}
