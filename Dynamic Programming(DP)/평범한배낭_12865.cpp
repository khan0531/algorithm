#include <bits/stdc++.h>

using namespace std;

int n, k;
int d[105][100005]; // d[i][j]: i번째 물건까지 탐색 했고, j 무게까지 담았을 때 가치의 최댓값
pair<int, int> p[105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if(j < p[i].first) d[i][j] = d[i - 1][j];
            else {
                d[i][j] = max(d[i - 1][j - p[i].first] + p[i].second, d[i - 1][j]);
            }
        }
    }
    cout << d[n][k];
}