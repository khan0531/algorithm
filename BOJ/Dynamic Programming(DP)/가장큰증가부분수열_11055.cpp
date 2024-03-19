#include <bits/stdc++.h>

using namespace std;

int d[1005];
int arr[1005];
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a; cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> arr[i];
        d[i] = arr[i];
    }
    // 1 100 2 50 60 3 5 6 7 8
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) d[i] = max(d[i], d[j] + arr[i]);
        }
            ans = max (ans, d[i]);
    }
    cout << ans;
}