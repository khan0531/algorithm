#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m;
int snack[1'000'005];

bool check(ll x) {
    ll cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += snack[i]/x;
    }
    return cnt >= n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> snack[i];
    } 

    ll st = 1, en = *max_element(snack, snack + m);
    while(st < en) {
        ll mid = (st + en + 1) / 2;

        if (check(mid)) st = mid;
        else en = mid - 1;
    }
    if (!check(st)) cout << 0;
    else cout << st;
}
