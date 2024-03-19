#include <bits/stdc++.h>

using namespace std;

int n, m, a, cnt;
vector<int> u[105];
vector<int> uu[105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            u[i].push_back(a);
        }
    }

    for (int i = 0; i < m; i++) {
        sort(u[i].begin(), u[i].end());
    }

    for (int i = 0; i < m; i++) {
        for (int cur : u[i]) {
            int lb = lower_bound(u[i].begin(), u[i].end(), cur) - u[i].begin();
            uu[i].push_back(lb);
        }
    }

    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            bool is_same = true;
            for (int k = 0; k < n; k ++){
                if (uu[i][k] != uu[j][k]){
                    is_same = false;
                    break;
                }
            }
            if (is_same) cout << i <<' ' << j << ' ' << cnt << '\n';
        }
    }

    cout << cnt;
    
}
