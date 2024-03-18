#include <bits/stdc++.h>

using namespace std;

int k, n;
int r[10005];

bool check(long long x){
    long long cnt = 0;
    for (int i = 0; i < k; i++) {
        cnt += r[i] / x;
    }
    return cnt >= n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> r[i];
    }
    long long st = 0;
    long long en = (1 << 31) - 1;
    while(st < en){
        long long mid = (st + en + 1)/2;
        if(check(mid)) st = mid;
        else en = mid - 1;
    }
    cout << st;
}