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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 1; i <= n; i++) g[i] = i; // 각 원소를 자신의 부모로 초기화
    
    // 연결 정보 입력 받기
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            if (a == 1) isSameGroup(i, j); // 두 도시가 연결된 경우 그룹 합치기
        }
    }
    
    // 여행 계획 입력 받기
    vector<int> trip(m);
    for (int i = 0; i < m; i++) {
        cin >> trip[i];
    }
    
    // 여행 계획에 있는 모든 도시들이 같은 그룹에 속하는지 확인
    for (int i = 0; i < m - 1; i++) {
        if (find(trip[i]) != find(trip[i + 1])) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
