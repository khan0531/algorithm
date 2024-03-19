#include <bits/stdc++.h>

using namespace std;

long long arr[100001];
int cnt = 0, mx = 0;
long long ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    //1 1 1 2 2
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] == arr[i - 1]) cnt++;
        else {
            if (mx < cnt){
                mx = cnt;
                ans = arr[i - 1];
            }
            cnt = 1;
        }
    }
    if (cnt > mx) ans = arr[n - 1];
    cout<< ans;
}