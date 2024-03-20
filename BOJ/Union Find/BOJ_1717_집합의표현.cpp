#include <bits/stdc++.h>

using namespace std;

vector<int> g;

int find(int x) {
    if (g[x] == x) return x;
    return g[x] = find(g[x]);
}

bool isSameGroup(int x, int y) {
    x = find(x); y = find(y); 
    if (x == y) return true; 
    g[y] = x;
    return false;
}

bool isSameGroup2(int x, int y) {
    x = find(x); y = find(y);
    return x == y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 1; i <= n; i++) g[i] = i; // 각 원소를 자신만의 그룹으로 초기화
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) isSameGroup(b, c); // 0인 경우 두 원소를 같은 그룹으로 병합
        if (a == 1) {
            if (!isSameGroup2(b, c)) cout << "NO\n"; // 다른 그룹인 경우 "NO" 출력
            else cout << "YES\n"; // 같은 그룹인 경우 "YES" 출력
        }
    }
    return 0;
}
