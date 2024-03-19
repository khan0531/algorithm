#include <bits/stdc++.h>

using namespace std;

int ans;
int a[55];
int k;

vector<string> parse(string s){
    vector<string> v;
    string cur = "";
    for(auto c : s){
        if(c == '-' || c == '+'){
            v.push_back(cur);
            cur = c;
            v.push_back(cur);
            cur = "";
        }
        else cur += c;
    }
    v.push_back(cur);
    return v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s; cin >> s;
    vector<string> v = parse(s);
    int sz = v.size();
    for (int i = 0; i < sz; i++) {
        if(v[i] != "-"){
            if(v[i] == "+") continue;
            a[k] += stoi(v[i]);
        }
        else k++;
    }
    ans += a[0];
    for (int i = 1; i <= k; i++) {
        ans -= a[i];
    }
    cout << ans;
}
