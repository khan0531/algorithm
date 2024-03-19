#include <bits/stdc++.h>

using namespace std;

int n, mn = 10000000, mx, sum;
int a[15];
int cal[4];

void func(int ans, int k){
    if (k == n){
        mn = min(ans, mn);
        mx = max(ans, mx);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (cal[i] == 0) continue;
        cal[i]--;
        if (i == 0) func(ans + a[k], k + 1);
        else if (i == 1) func(ans - a[k], k + 1);
        else if (i == 2) func(ans * a[k], k + 1);
        else if (i ==3) func(ans / a[k], k + 1);
        cal[i]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> cal[i];
    }


}
