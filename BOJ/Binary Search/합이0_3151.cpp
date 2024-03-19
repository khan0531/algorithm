#include <bits/stdc++.h>

using namespace std;

vector<int> a;
long long ans;
vector<int> two_score;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a.push_back(k);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            long long cnt = upper_bound(a.begin() + j + 1, a.begin() + n, -(a[i]+ a[j])) - lower_bound(a.begin() + j + 1, a.begin() + n, -(a[i]+ a[j]));
            ans += cnt;
        }
    }
    cout <<  ans;
}