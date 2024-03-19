#include <bits/stdc++.h>

using namespace std;

int n;
long long cnt;
int a[100005];
bool is_used[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int st = 0;
    int en = 0;
    while(st < n){
        if(!is_used[a[en]] && en < n){
            is_used[a[en]] = true;
            en++;
        }
        else {
            is_used[a[st]] = false;
            cnt += (en - st);
            st++;
        }
    }
    cout << cnt;
}