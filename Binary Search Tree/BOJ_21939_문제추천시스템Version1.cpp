#include <bits/stdc++.h>

using namespace std;

multiset<pair<int, int>> ms; //{난이도, 문제 번호}
int a[100005]; //m[번호] = 난이도

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p, l;
        cin >> p >>l;
        ms.insert({l, p});
        a[p] = l;
    }
    int m; cin >> m;
    while(m--){
        string s;
        cin >> s;
        if(s == "recommend"){
            int x; cin >> x;
            if(x == 1){
                auto it = prev(ms.end());
                cout << it->second << '\n';
            }
            else {
                auto it = ms.begin();
                cout << it->second << '\n';
            }
        }
        else if(s == "add"){
            int p, l; cin >> p >> l;
            ms.insert({l, p});
            a[p] = l;
        }
        else {
            int p; cin >> p;
            ms.erase({a[p], p});
        }
    }
}