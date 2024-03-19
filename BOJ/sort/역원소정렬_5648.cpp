#include <bits/stdc++.h>

using namespace std;

vector<long long> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;


    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        v.push_back(stoll(s));
    }

    sort(v.begin(), v.end());

    for (long long c : v) {
        cout << c << '\n';
    }
}