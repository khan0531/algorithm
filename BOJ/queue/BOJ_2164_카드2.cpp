#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    queue<int> Q;

    for (int i = 0; i < n; i++) {
        Q.push(i + 1);
    }
    if (Q.size() == 1 && Q.front() == 1) cout << 1;
    else{
        for (int i = 1; i < n; i++) {
          if (Q.size() == 2) cout << Q.back();
             else{
                 Q.pop();
                 Q.push(Q.front());
                 Q.pop();
                 }
            }
    }
}