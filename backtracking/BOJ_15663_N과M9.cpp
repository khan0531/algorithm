#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[10];
int ans[10];
bool isused[10];

void func(int k){
    if (k == m){
        for (int i = 0; i < m; i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    int temp = 0;
    for (int i = 0; i < n; i++) {
        if (isused[i] || temp == arr[i]) continue;
        ans[k] = arr[i];
        temp = ans[k];
        isused[i] = true;
        func(k + 1);
        isused[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    func(0);
}