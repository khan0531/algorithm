#include <bits/stdc++.h>

using namespace std;

int n, k;
const int MAX = 0x3f3f3f3f;
int d[15][15];
vector<int> p;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        if (i == k) continue;
        p.push_back(i);
    }
    
    for (int i = 0; i < n; i++) {
        fill(d[i], d[i] + n, MAX);
    }

    int a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            d[i][j] = min(d[i][j], a);
        }
    }

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    int ans = MAX;
    do{
        int temp = d[k][p[0]];
        for (int i = 1; i < n - 1; i++) {
            temp += d[p[i - 1]][p[i]];
        }
        ans = min(ans, temp);
    }while(next_permutation(p.begin(), p.end()));

    cout << ans;
}
