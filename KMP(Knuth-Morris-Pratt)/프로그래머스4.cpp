#include <bits/stdc++.h>

using namespace std;

string magazine;
string phrase;

vector<int> failure(string& s){
    vector<int> f(s.size());
    int j = 0;
    for (int i = 1; i < s.size(); i++){
        while(j > 0 && s[i] != s[j]) j = f[j - 1];
        if (s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

bool kmp(string& a, string& b){
    vector<int> f = failure(b);
    int j = 0;
    for (int i = 0; i < a.size(); i++){
        while(j > 0 && a[i] != b[j]) j = f[j - 1];
        if (a[i] == b[j]) j++;
        if (j == b.size()) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, magazine);
    getline(cin, phrase);

    int ans = 0;
    string cur = "";
    for (char c : phrase){
        if (c == ' '){
             ans++;
             cur = "";
             continue;
        }
        cur += c;
        if (!kmp(magazine, cur)){
            ans++;
            cur = c;
        }
    }
    ans++;

    cout << ans;
}
