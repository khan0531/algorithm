#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000005];
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    v.push_back(a[0]);

    for (int i = 1; i < n; i++) {
        int idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        if (idx == v.size()) v.push_back(a[i]);
        else v[idx] = a[i]; 
    }

    cout << v.size();
}
