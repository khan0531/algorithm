#include <bits/stdc++.h>

using namespace std;

long long ans;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    while(n--){
        int size; cin >> size;
        pq.push(size);
    }
    while(pq.size() > 1){
        int k = 0;
        k += pq.top();
        pq.pop();
        k += pq.top();
        pq.pop();
        ans += k;
        pq.push(k);
    }
    cout << ans;
}