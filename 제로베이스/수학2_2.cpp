#include <bits/stdc++.h>

using namespace std;

char c[1005];
int d[1005];
string S;
void manacher(string s){
    int sz = s.size();
    int r = 0, p = 0;
    for (int i = 0; i < sz; i++){
        if (r < i) d[i] = 0;
        else d[i] = min(r - i, d[2*p - i]);

        while(i - d[i] - 1 >= 0 && i + d[i] + 1 < sz && s[i - d[i] - 1] == s[i + d[i] + 1]) d[i]++;
        if (r < i + d[i]){
            r = i + d[i];
            p = i;
        }
    }
}

string ss(int k){
    string s1 = "0";
    for (int i = 0; i < S.size(); i++) {
        if (i == k) continue;
        s1 += S[i];
        s1 += "0";
    }
    
    return s1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;

    for (int i = 0; i < S.size(); i++) {
        d[i][i] = true;
    }

    for (int i = 0; i < S.size(); i++) {
       if (S[i] == S[i + 1]) d[i][i+1] = true;
    }

    for (int k = 2; k <= n - 1; k++){
        for (int i = 1; i <= n - k; i++) {
            int j = i + k;
            if (S[i] == S[j] && d[i + 1][j - 1]) d[i][j] = true;
        }
    }



    string temp = "0";
    for (int i = 0; i < S.size(); i++) {
        temp += S[i];
        temp += "0";
    }
    
    manacher(temp);
    if (d[temp.size()/2] + temp.size()/2 == temp.size() - 1) {
        cout << 0;
        return 0;
    }

    else {
        for (int i = 0; i < S.size(); i++) {
            temp = ss(i);
            manacher(temp);
            if (d[temp.size()/2] + temp.size()/2 == temp.size() - 1) {
                cout << 1;
                return 0;
            }
        }
    }
    cout << 2;
}
