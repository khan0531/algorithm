#include <bits/stdc++.h>

using namespace std;

int a[500005];
int n;

int lb(int k){
    int st = 0;
    int en = n;
    while(st < en){
        int mid = (st + en) / 2;
        if(a[mid] >= k) en = mid;
        else st = mid + 1;
    }
    return st;
}

int ub(int k){
    int st = 0;
    int en = n;
    while(st < en){
        int mid = (st + en) / 2;
        if(a[mid] <= k) st = mid + 1;
        else en = mid;
    }
    return st;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int m; cin >> m;
    while(m--){
        int k; cin >> k;
        cout << ub(k) - lb(k) << ' ';
    }
}