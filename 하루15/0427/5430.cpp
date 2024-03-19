#include <bits/stdc++.h>

using namespace std;

int t;
vector<string> v;

void parse(string s){
    string ss = "";
    for (char c : s){
        if (c =='[' || c == ']') continue;

        else if (c == ',') {
            v.push_back(ss);
            ss = "";
        }
        
        else ss += c;
    }

    if (ss != "") v.push_back(ss);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;

    string q;
    int n;
    string s;
    while(t--){
        cin >> q;
        cin >> n;
        cin >> s;

        v.clear();
        parse(s);

        int cnt = 0;
        for (char c : q){
            if (c == 'D'){
                if (v.empty()) {
                    cout << "error" << '\n';
                    break;
                }

                if (cnt%2 == 0) v.erase(v.begin());
                else v.erase(v.end() - 1);
            }

            if (c == 'R') cnt++;
        }

        int sz = v.size();
        if (sz != 0) { 
            cout << '[';
            if (cnt%2 == 0){
                for (int i = 0; i < sz; i++) {
                    cout << v[i];
                    if (i != sz - 1) cout << ',';
                }
            }
            else {
                for (int i = sz - 1; i >= 0; i--) {
                    cout << v[i];
                    if (i != 0) cout << ',';
                }
            }
            cout << ']' << '\n';
        }
    }
}
