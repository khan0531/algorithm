#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const int INF = 1'000'000'007;
ll dp[105][105][105]; // i번째 건물을 세웠을 때, 왼쪽에서 j개 보이고, 오늘쪽에서 k개 보이는 가지수. 건물은 점점 작은 건물을 뒤에 세운다고 가정

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l, r;
    cin >> n >> l >> r; // n, l, r 입력 받기

    dp[1][1][1] = 1; // 기본 경우 설정
    for (int k = 2; k <= n; k++) {
        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= r; j++) {
                dp[k][i][j] = (dp[k - 1][i - 1][j] + dp[k - 1][i][j - 1] + dp[k - 1][i][j] * (k - 2)) % INF;
                // k번째 노드를 추가할 때, 왼쪽, 오른쪽, 중간에 노드를 추가하는 경우의 수를 모두 고려
            }
        }
    }
    cout << dp[n][l][r] << '\n'; // 결과 출력

    return 0;
}
