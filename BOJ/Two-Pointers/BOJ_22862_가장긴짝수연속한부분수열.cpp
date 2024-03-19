#include <bits/stdc++.h>

using namespace std;

int n, k, mx;
int a[1000005];
int cho[1000005];

bool is_even(int x){
    if(x%2 == 0) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int st = 0, en = 0, cnt = 0;// cnt가 홀수 개수
    while(st < n){
        if(en < n && cnt + a[en]%2 <= k){
            cnt += a[en]%2;
            en++;
        }
        else{
            mx = max(mx, en - st - cnt);
            cnt -= a[st]%2;
            st++;
        }
    }
    cout << mx;
}