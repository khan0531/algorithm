#include <bits/stdc++.h>

using namespace std;

pair <int, string> p[100005];
bool cmp(pair <int, string> a, pair <int, string> b){
    if (a.first < b.first) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    stable_sort(p, p+n, cmp);

    for (int i = 0; i < n; i++) {
        cout << p[i].first << ' ' << p[i].second << '\n';
    }
}