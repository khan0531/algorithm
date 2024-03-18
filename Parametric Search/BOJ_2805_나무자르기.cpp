#include <bits/stdc++.h>

using namespace std;

int n, m; // n이 나무의 수, m: 필요한 길이
int tree[1000005];
bool divid(int k){
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        if(tree[i] > k) cnt += (tree[i] - k);
    }
    return cnt >= m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }
    int st = 0;
    int en = *max_element(tree, tree+n);
    while(st < en){
        long long mid = (st + en + 1) / 2;
        if(divid(mid)) st = mid;
        else en = mid - 1;
    }
    cout << st;
}