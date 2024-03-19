#include <bits/stdc++.h>

using namespace std;

int n;
int a[10005];
int d[10005]; // i 번째 포도주의 양

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    d[0] = a[0];
    d[1] = a[0] + a[1];
    for (int i = 2; i < n; i++) {
        d[i] = max(d[i - 1], max(d[i - 2], d[i - 3] + a[i - 1]) + a[i]);
    }

   cout << d[n - 1];
}