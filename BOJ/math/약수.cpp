#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> v;

    for (int i = 1; i*i <= n; i++) {
        if(n % i != 0) continue;
        v.push_back(i);
        if(i == n/i) continue;
        v.push_back(n/i);
    }
    for(int i : v) cout << i << ' ';
}