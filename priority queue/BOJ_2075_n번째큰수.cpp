#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    int a = n*n;
    while(a--){
        int x; cin >> x;
        pq.push(x);
        if(pq.size() > n) pq.pop();
    }
    cout << pq.top();
}