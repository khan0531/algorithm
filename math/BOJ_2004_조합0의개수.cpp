#include <bits/stdc++.h>

using namespace std;


int func(int n, int i){
    long long cnt = 0, cur = i;
    while(n / i){
        cnt += (n / i);
        i *= i;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;

    func(n, 2);

    int ans = min(func(n, 5) - func(m, 5) - func(n - m, 5), func(n, 2) - func(m,2) - func(n - m, 2));

    cout << ans;
}