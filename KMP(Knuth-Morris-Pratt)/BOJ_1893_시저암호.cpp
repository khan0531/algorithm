#include <bits/stdc++.h>

using namespace std;

vector<int> failure(string& s){
    vector<int> f(s.size());
    int j = 0;
    for (int i = 1; i < s.size(); i++) {
        while(j > 0 && s[i] != s[j]) j = f[j - 1];
        if (s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    string a, w, s;

    while(n--){
        cin >> a;
        cin >> w;
        cin >> s;

        int az = a.size();
        int aa[300] = {}; //a의 배열의 순서를 저장.
        int ma[300] = {};
        for (int i = 0; i < az; i++) {
            aa[a[i]] = i;
        }

        int cnt[65] = {}; //시프트 값 구할 것. cnt 값이 1이면 구하고자 하는 시프트 값이다.
        vector<int> f = failure(w);
        
        for (int k = 0; k < az; k++) {
            for (int i = 0; i < az; i++) 
                ma[a[i]] = (aa[a[i]] + k)%az;

            int j = 0;
            for (int i = 0; i < s.size(); i++) {
                while(j > 0 && aa[s[i]] != ma[w[j]]) j = f[j - 1];
                if (aa[s[i]] == ma[w[j]]) j++;
                if (j == w.size()){
                    j = f[j - 1];
                    cnt[k]++;
                    if (cnt[k] > 1) break;
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < az; i++) {
            if (cnt[i] == 1) ans.push_back({i});
        }
        if (ans.size() == 0) cout << "no solution" <<'\n';
        else if (ans.size() == 1) cout << "unique: " << ans[0] << '\n';
        else {
            cout << "ambiguous: ";
            for (int i : ans) cout << i << ' ';
            cout << '\n';
        }
    }
}
