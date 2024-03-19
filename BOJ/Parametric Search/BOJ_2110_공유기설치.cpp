#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, c;
int house[200'005];

 // 일정한 간격(x)마다 공유기를 설치 하는데, 설치할 수 있는 공유기의 값이 최소일 때가 x가 가장 크다.
bool check(ll x) {
    ll cnt = 0;
    ll idx = 0;
    while (idx < n) {
        cnt++;
        idx = lower_bound(house, house + n, house[idx] + x) - house;
    }
    return cnt >= c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> house[i];
    }

    sort(house, house + n);

    ll st = 0, en = *max_element(house, house + n);
    while(st < en) {
        ll mid = (st + en + 1) / 2;
        if (check(mid)) st = mid;
        else en = mid - 1;
    }
    cout << st;
}
