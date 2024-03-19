#include <bits/stdc++.h>

using namespace std;

bool d[2005][2005]; // d[i][j]: 수열의 i번째부터 j번째까지의 구간이 팰린드롬인지 여부를 저장하는 배열
int a[2005]; // 수열의 각 원소를 저장하는 배열

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n; // 수열의 길이 입력
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; // 수열의 원소 입력
    }
    // 기저 사례 처리: 모든 단일 원소는 팰린드롬입니다.
    for (int i = 1; i <= n; i++) {
        d[i][i] = true;
    }
    // 두 원소가 같은 경우, 이들로 구성된 구간도 팰린드롬입니다.
    for (int i = 1; i <= n - 1; i++) {
        if (a[i] == a[i + 1]) d[i][i + 1] = true;
    }
    // 길이가 3 이상인 구간에 대해 팰린드롬 여부 판별
    for (int k = 2; k <= n - 1; k++){
        for (int i = 1; i <= n - k; i++) {
            int j = i + k;
            // a[i]와 a[j]가 같고, 그 사이 구간이 팰린드롬이면, 전체 구간도 팰린드롬입니다.
            if (a[i] == a[j] && d[i + 1][j - 1]) d[i][j] = true;
        }
    }
    // 쿼리 처리: 각 쿼리는 a와 b로 구성되며, a부터 b까지의 구간이 팰린드롬인지 출력합니다.
    int m; cin >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        cout << d[a][b] << '\n';
    }
}
