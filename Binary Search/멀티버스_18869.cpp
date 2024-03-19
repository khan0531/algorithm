#include <bits/stdc++.h>

using namespace std;

int m, n;
int cnt;
int a[105][10005];

void func(int a[]){
    vector<int>v(a, a + n);
    v.erase(unique(v.begin(), v.end()), v.end());
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    }
}

bool com(int a[], int b[]){
    for (int i = 0; i < n; i++) {
        if(a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
        func(a[i]);
    }

    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if(com(a[i], a[j])) cnt++;
        }
    }
    cout << cnt;
}