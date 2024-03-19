#include <bits/stdc++.h>

using namespace std;

int n;
int a[1005];
int a1[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int k1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            a1[k1++] = a[i] + a[j];
        }
    }
    sort(a1, a1 + n*(n + 1) / 2);
    // for (int i = 0; i < n*(n + 1) / 2; i++) {
    //     cout << a1[i] << ' ' << '\n';
    // }

    for (int i = n - 1; i >= 0; i--) {
        bool exist = false;
        for (int j = 0; j < n; j++) {
            if(binary_search(a1, a1 + n*(n + 1)/2, a[i] - a[j])){
                cout << a[i] << '\n';
                exist = true;
                break;
            }
        }
        if(exist) break;
    }
}