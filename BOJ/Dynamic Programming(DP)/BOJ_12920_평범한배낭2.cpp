#include <bits/stdc++.h>

using namespace std;

int d[10005][10005]; //i 번째까지 탐색 했을 때 j 무게를 넣었고 그 때의 최댓값.
vector<pair<int, int>> p;
bool check(int n){
    bool two = true;
    while(n > 1){
        if(n%2 == 1){
            two = false;
            break;
        }
        n /= 2;
    }
    
    return two;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    p.push_back({0, 0});
    while(n--) {
        int v, c, k;
        cin >> v >> c >> k;
        int j = 1; // 이진 분해 시작 값 (2의 0제곱)
        int temp;
        while(k > 0){
            temp = min(k, j);  // 현재 단계에서 처리할 수 있는 최대 항목 개수
            p.push_back({v*temp, c*temp}); // 이진 분해된 항목을 p 벡터에 추가
            j *= 2; // 다음 이진 분해 단계로 이동 (2의 거듭제곱 증가)
            k -= temp; // 남은 항목 개수 감소
        }
    }

    for (int i = 1; i < p.size(); i++) {
        for (int j = 1; j <= m; j++) {
            if(j < p[i].first) d[i][j] = d[i - 1][j];
            else{
                d[i][j] = max(d[i - 1][j - p[i].first] + p[i].second, d[i - 1][j]);
            }
        }
    }
    cout << d[p.size() - 1][m];
}