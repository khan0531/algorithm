#include <bits/stdc++.h>

using namespace std;

int n, s, sum, cnt;
int a[100005];
int mn = 1000000000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int st = 0, en = 0;
    while(en < n){
        if(sum < s){
            en++;
            sum += a[en];
            cnt++;
        }
        else{
            mn = min(mn, cnt);
            sum -= a[st];
            st++;
            cnt--;
        }
    }
    if(mn == 1000000000) cout << 0;
    else cout << mn;
}