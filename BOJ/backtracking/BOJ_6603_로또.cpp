#include <bits/stdc++.h>

using namespace std;

int arr[50];
int ans[50];
bool isused[50];
int n;

void func(int k){
    if(k == 6){
        for (int i = 0; i < 6; i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isused[i] || ans[k - 1] > arr[i]) continue;
        ans[k] = arr[i];
        isused[i] = true;
        func(k + 1);
        isused[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        func(0);
        cout << '\n';
    }
}