#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >>t;
    while(t--){
        multiset<int> ms;
        int k; cin >> k;
        while(k--){
            char c;
            int n;
            cin >> c >> n;
            if(c == 'I') ms.insert(n);
            else {
                if(ms.empty()) continue;
                auto it1 = ms.begin();
                auto it2 = prev(ms.end());
                if(n == 1) ms.erase(it2);
                else ms.erase(it1);
            
            }
        }
        if(ms.empty()) cout << "EMPTY" << '\n';
        else {
            auto it1 = ms.begin();
            auto it2 = prev(ms.end());

            cout << *it2 << ' ' << *it1 << '\n';
        }
    }
}