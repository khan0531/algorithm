#include <bits/stdc++.h>

using namespace std;

int n;
string s;
vector<string> v;

bool cmp(string a, string b) {
    if (a.length() < b.length()) return a.length() < b.length();
    if (a.length() == b.length()) {
        int asum = 0;
        int bsum = 0;
        for (char c : a){
            if (isdigit(c)) asum += c - '0'; 
        }
        for (char c : b){
            if (isdigit(c)) bsum += c - '0';
        }
       if (asum == bsum) return a < b;
       else return asum < bsum;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while(n--){
        cin >> s;
        v.push_back(s);
    }
    
    sort(v.begin(), v.end(), cmp);

    for(string cur : v) cout << cur << '\n';
}
