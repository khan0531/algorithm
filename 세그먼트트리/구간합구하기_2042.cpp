#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// typedef long long ll;

int n, m, k;
ll a[1'000'005];
ll t[2'000'005];

void init(int st, int en, int idx) {
    if (st == en){
        t[idx] = a[st];
        return;
    }

    init(st, (st+en)/2, idx*2);
    init((st+en)/2+1, en, idx*2+1);
    t[idx] = t[2*idx] + t[2*idx+1];
}

ll query(int st, int en, int idx, int left, int right) {
    ll ans = 0;
    if (st == left && en == right){
       return t[idx];
    }
    if (right <= (st + en)/2)  ans += query(st, (st+en)/2, idx*2, left, right);
    else if (left > (st + en)/2) ans += query((st+en)/2+1, en, idx*2+1, left, right);
    else {
        ans += query(st, (st+en)/2, idx*2, left, (st+en)/2);
        ans += query((st+en)/2+1, en, idx*2+1, (st+en)/2+1, right);
    }
    return ans;
}

void update(int st, int en, int idx, int newIdx, ll newValue) {
    if (st == en){
        t[idx] = newValue;
        return;
    }

    if (newIdx <= (st + en)/2) update(st, (st+en)/2, idx*2, newIdx, newValue);
    else update((st + en)/2+1, en, idx*2+1, newIdx, newValue);
    t[idx] = t[2*idx] + t[2*idx+1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    m += k;
    init(0, n - 1, 1);

    while (m--) {
        ll op, b, c; cin >> op >> b >> c;

        if (op == 1) update(0, n - 1, 1, b - 1, c);
        else cout << query(0, n - 1, 1, b - 1, c - 1) << '\n';
    }
}
