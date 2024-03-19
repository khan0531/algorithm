#include <bits/stdc++.h>

using namespace std;

int n, l;
priority_queue<pair<int, int>, 
            vector<pair<int, int>>,
            greater<pair<int, int>>> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    for (int i = 0; i < n; i++){
        int a; cin >> a;
        while (!q.empty() && i - q.top().second >= l) q.pop();
        q.push({a, i});
        cout << q.top().first << ' ';
    }
}
