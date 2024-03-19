#include <bits/stdc++.h>

using namespace std;

int n, sum;
int a[80005];
int cnt[80005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    stack<int> s;
    s.push(1000000001);

    for (int i = n; i > 0; i--) {
        if (a[i] <= s.top()) {
            cnt[i] = 0;
            s.push(a[i]);
        }
        else {
            int cn = 0;
            while (s.top() <= a[i]){
                s.pop();
                cn++;
            }
            cnt[i] = cnt[i - 1] + cn;
        }
        sum += cnt[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << ' ';
    }
    cout << sum;
}