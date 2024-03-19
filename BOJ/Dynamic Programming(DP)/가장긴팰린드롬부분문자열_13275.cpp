#include <bits/stdc++.h>

using namespace std;

int d[200005];
int ans;
void manacher(string s, int n){
    int r = 0;
    int p = 0;
    for (int i = 0; i < n; i++) {
        if(r < i) d[i] = 0;
        else d[i] = min(r - i, d[2*p - i]);
        while(i - d[i] - 1 >= 0 && i + d[i] + 1 < n && s[i - d[i] - 1] == s[i + d[i] + 1]) d[i]++;
        if(r < i + d[i]){
            r = i + d[i];
            p = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s = "", temp = "";
    cin >> s;
    int sz = s.size();
    for (int i = 0; i < sz; i++) {
        temp += "#";
        temp += s[i]; 
    }
    temp += "#";

    sz = temp.size();
    manacher(temp, sz);
    for (int i = 0; i < sz; i++) {
        ans = max(ans, d[i]);
    }
    cout << ans;
}