#include <bits/stdc++.h>

using namespace std;

int n, d, k, c, mx;
int a[33005];
int cnt[3005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //회전하는거 생각해서 셋팅
    for (int i = n; i < n + k - 1; i++) {
        a[i] = a[i - n];
    }
    //처음 네개 셋팅
    int st = 0, en = 0, sum = 0;
    while(en - st < k){
        cnt[a[en]]++;
        if(cnt[a[en]] == 1) sum++;
        en++;
    }

    while(en < n + k -1){
        cnt[a[en]]++;
        if(cnt[a[en]] == 1) sum++;
        cnt[a[st]]--;
        if(cnt[a[st]] == 0) sum--;
        st++;
        en++;
        if(cnt[c] == 0){
            mx = max(mx, sum + 1);
        }
        else mx = max(mx, sum);
    }
    cout << mx;
}