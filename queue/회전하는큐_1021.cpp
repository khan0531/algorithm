#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    deque<int> d;
    for (int i = 1; i <= n; i++) {
        d.push_back(i);
    }

    int a;
    while(m--){
        cin >> a;

        int idx;
        int sz = d.size();
        for (int i = 0; i < sz; i++) {
            if (d[i] != a) continue;
            idx = i;
            break;
        }
        if (2*idx <= sz){
            for (int i = 0; i < idx; i++) {
                int f = d.front();
                d.pop_front();
                d.push_back(f);
                cnt++;
            }
            d.pop_front();
        }
        else {
            for (int i = 0; i < sz - idx; i++) {
                int b = d.back();
                d.pop_back();
                d.push_front(b);
                cnt++;
            }
            d.pop_front();
        }
    }
    cout << cnt;
}
