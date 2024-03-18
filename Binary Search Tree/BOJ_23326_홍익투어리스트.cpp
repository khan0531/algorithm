#include <bits/stdc++.h>

using namespace std;

bool issight[500005]; // 명소인지 판별
set<int> sight; // 명소 넣어두기

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int loc = 0; // 현재 도현이 위치
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x == 1) {
            issight[i] = true;
            sight.insert(i);
        }
    }
    while(q--){
        int x; cin >> x;
        if(x == 1){
            int y; cin >> y;
            if(issight[y - 1]) {
                issight[y - 1] = false;
                sight.erase(y - 1);
            }
            else {
                issight[y - 1] = true;
                sight.insert(y - 1);
            }
        }
        else if (x == 2){
            int y; cin >> y;
            loc += y;
            loc %= n; 
        }
        else {
            if(sight.size() == 0) cout << -1 << '\n';
            else {
                auto it = sight.lower_bound(loc);
                if(it == sight.end()) {
                    it = sight.begin();
                    cout << *it + n - loc << '\n';
                }
                else cout << *it - loc <<'\n';
            }
        }
    }
}