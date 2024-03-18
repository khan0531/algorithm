#include <bits/stdc++.h>

using namespace std;

int n;
long long m;
long long a[1000005];
long long mn = 2000000001;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    int st = 0, en = 0;
    while(en < n){
        if(a[st] + m > a[en]) en++;
        else {
            mn = min(mn, a[en] - a[st]);
            st++;
        }
    }
    cout << mn;
}