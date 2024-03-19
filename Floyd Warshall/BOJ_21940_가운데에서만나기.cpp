#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, t, K;
int c[205];
const int MAX = 0x3f3f3f3f;
int d[205][205];
vector<int> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        fill(d[i], d[i] + n + 1, MAX);
    }

    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }

    while(m--){
        cin >> a >> b >> t;
        d[a][b] = t;
    }

    cin >> K;
    for (int i = 1; i <= K; i++){
        cin >> c[i];
    }


    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    vector<pair<int, int>> mxs;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        int mx = 0;
        for (int j = 1; j <= K; j++) {
            sum = d[i][c[j]] + d[c[j]][i];
            mx = max(mx, sum);
        }
        mxs.push_back({mx, i});
    }

    sort(mxs.begin(), mxs.end());
    for (int i = 0; i < mxs.size(); i++) {
        if (mxs[i + 1].first != mxs[i].first) {
            cout << mxs[i].second << ' ';
            break;
        }
        cout << mxs[i].second << ' ';
    }
}
