#include <bits/stdc++.h>

using namespace std;
int n, k, mx;
int a[200005];
int cnt[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int st = 0, en = 0;
    cnt[a[0]]++;
    while(en < n){
        if(cnt[a[en]] > k){
            cnt[a[st]]--;
            st++;
        }
        else{
            en++; 
            cnt[a[en]]++;
            mx = max(mx, en - st);
        }
    }
    cout << mx;
}