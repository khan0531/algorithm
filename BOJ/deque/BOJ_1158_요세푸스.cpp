#include <bits/stdc++.h>

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;

    deque<int> d1, d2;
    for (int i = 1; i <= N; i++) {
        d1.push_back(i);
    }

   while(!d1.empty()){
        for (int i = 1; i < K; i++) {
            d1.push_back(d1.front());
            d1.pop_front();
        }
        d2.push_back(d1.front());
        d1.pop_front();
    }

    cout << '<';
    int sz = d2.size();
    for (int i = 0; i < sz; i++) {
        cout << d2.front();
        d2.pop_front();
        
        if (d2.empty()) continue;
        cout << ", ";
    }
    cout << '>';
}