#include <bits/stdc++.h>

using namespace std;

int d[1005];
int arr[1005];
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >>n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        d[i] = 1;
    }
    //10 20 10 30 20 50
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) d[i] = max(d[i], d[j] + 1);
        }
        ans = max(ans, d[i]);
    }
    cout << ans;
}