#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, c;
int a;
map <ll, int> m;
map <ll, int> m1;
vector<pair<ll, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second > b.second) return a > b;
    else if (a.second == b.second) return m1[a.first] < m1[b.first];
    return false;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;

    for (int i = 1; i <= n; i++) {
        cin >> a;
        m[a]++;
        if (m1[a] == 0){
            m1[a] = i;
        }
        else continue;
    }

    for (auto cur : m){
        v.push_back(cur);
    }

    stable_sort(v.begin(), v.end(), cmp);
    
    for (auto cur : v) {
        while (cur.second--) cout << cur.first << ' ';
    }
}