#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, x, y;
ll len;
vector<pair<int, int>> v;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while(n--) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    
    sort(v.begin(), v.end());
    auto pre = v[0];
    int mx = pre.second;
    len = pre.second - pre.first;

    for (auto cur : v){
        auto [a, b] = cur;
        if (a <= mx) {
            if (b > mx) {
                len += (b - mx);
                mx = b;
            }
        }
        else {
            len += (b - a);
            mx = b;
        }
    }
    
    cout << len;
}
