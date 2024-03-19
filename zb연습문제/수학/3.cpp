#include <bits/stdc++.h>

using namespace std;

string s1, s2;
char c[105];
bool isused[105];

vector<int> a;
vector<vector<int>> aa;
int b[20];
int bb[20][20];

vector<int> failure(string& s){
    vector<int> f(s.size());
    int j = 0;
    for (int i = 1; i < s.size(); i++) {
        while(j > 0 && s[i] != s[j]) j = f[j - 1];
        if (s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

void permutation(int k){
    bool istrue = false;
    if (k == s1.size()){
        string ss = "";
        for (int i = 0; i < s1.size(); i++) {
            ss += c[i];
        }
        vector<int> f = failure(ss);
        int j = 0;

        for (int i = 0; i < s2.size(); i++) {
            while (j > 0 && s2[i] != ss[j]) j = f[j - 1];
            if (s2[i] == ss[j]) j++;
            if (j == ss.size()) {
                cout << ss << ' ' << "True" << '\n';
                return;
            }
        }
        cout << ss << ' ' << "False"<<'\n';
        return;
    }

    for (int i = 0; i < s1.size(); i++) {
        if (isused[i]) continue;
        isused[i] = true;
        c[k] = s1[i];
        permutation(k + 1);
        isused[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s, t;
    cin >> s1 >> s2;
    permutation(0);
}