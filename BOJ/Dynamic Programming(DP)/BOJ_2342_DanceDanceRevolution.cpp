#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset을 사용하기 위함
using namespace std;

const int INF = 0x3f3f3f3f;
int dp[100001][5][5];
int force[5][5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 힘 배열 초기화
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (i == 0 || j == 0) force[i][j] = 2;
            else if (i == j) force[i][j] = 1;
            else if (i + j == 4 || i + j == 6) force[i][j] = 4;
            else force[i][j] = 3;
        }
    }

    // dp 배열 초기화
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;

    int a, cnt = 1;
    while (true) {
        cin >> a;
        if (a == 0) break;

        for (int i = 0; i < 5; ++i) {
            if (a == i) continue; // 같은 위치에 발을 둘 수 없음
            for (int j = 0; j < 5; ++j) {
                dp[cnt][a][i] = min(dp[cnt][a][i], dp[cnt-1][j][i] + force[j][a]);
            }
        }

        for (int i = 0; i < 5; ++i) {
            if (a == i) continue;
            for (int j = 0; j < 5; ++j) {
                dp[cnt][i][a] = min(dp[cnt][i][a], dp[cnt-1][i][j] + force[j][a]);
            }
        }

        cnt++;
    }

    int mn = INF;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            mn = min(mn, dp[cnt-1][i][j]);
        }
    }

    cout << mn << '\n';
    return 0;
}
