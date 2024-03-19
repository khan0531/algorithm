#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b){
    int s1 = a.size();
    int s2 = b.size();
    int sum1 = 0;
    int sum2 = 0;
    if (s1 < s2) return true;
    else if(s1 == s2){
        for (int i = 0; i < s1; i++) {
            if(isdigit(a[i])) sum1 += (a[i] - '0');
            if(isdigit(b[i])) sum2 += (b[i] - '0');
        }
        if(sum1 < sum2) return true;
        else if (sum1 == sum2){
            if (a < b) return true;
        }
    }
    return false;
}

vector<string> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), cmp);

    for (string s : v) cout << s << '\n';
}