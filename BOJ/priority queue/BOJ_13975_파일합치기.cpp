#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long ans = 0;
        int k; cin >> k;
        while(k--){
            int x; cin >> x;
            pq.push(x);
        }
        while(pq.size() > 1){
            long long k = 0;
            k += pq.top();
            pq.pop();
            k += pq.top();
            pq.pop();
            ans += k;
            pq.push(k);
        }
        cout << ans <<'\n';
    }
}