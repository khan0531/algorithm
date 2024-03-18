#include <bits/stdc++.h>

using namespace std;

int n;
unordered_map<string, int> m;
vector<string> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        string s, s1;
        cin >> s >> s1;
        if(s1 == "enter") m[s]++;
        else m[s]--;
    }
    for(auto c : m){
        if(c.second > 0) v.push_back(c.first);
    }
    sort(v.begin(), v.end(), greater<string>());
    for(string s : v) cout << s << '\n';    
}