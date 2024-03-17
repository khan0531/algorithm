#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, K;
ll r;
const int MAX = 0x3f3f3f3f;
ll d[105][105]; // 내일로 티켓 샀을 때
ll dd[105][105]; // 내일로 안샀을 때
map<string, int> c;
int t[205];
string city;
string trip;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r;
    int cnt = 0;
    int k = 1;
    for (int i = 1; i <= n; i++) {
        cin >> city;
        if (c[city]) {
            cnt++;
            continue;
        }
        c[city] = k++;
    }
    n -= cnt; // 중복 되는 도시 삭제

    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> trip;
        t[i] = c[trip];
    }

    for (int i = 1; i <= n; i++) {
        fill(d[i], d[i] + n + 1, MAX);
        fill(dd[i], dd[i] + n + 1, MAX);
    }

    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
        dd[i][i] = 0;
    }

    cin >> K;
    string type, s, e;
    ll cost;
    while(K--){
        cin >> type >> s >> e >> cost;
        cost *= 2;
        dd[c[s]][c[e]] = min(dd[c[s]][c[e]], cost);
        dd[c[e]][c[s]] = dd[c[s]][c[e]];

        if (type == "S-Train" || type == "V-Train") cost /= 2;
        else if (type == "ITX-Saemaeul" || type == "ITX-Cheongchun" || type == "Mugunghwa") cost = 0;
        d[c[s]][c[e]] = min(d[c[s]][c[e]], cost);
        d[c[e]][c[s]] = d[c[s]][c[e]];
    }
    
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
                if (dd[i][j] > dd[i][k] + dd[k][j]) dd[i][j] = dd[i][k] + dd[k][j];
            }
        }
    }

    ll sum = 2*r;
    for (int i = 1; i < m; i++) {
        sum += d[t[i]][t[i+1]];
        sum -= dd[t[i]][t[i+1]];
    }
    cout << sum << '\n';
    if (sum <= 0) cout << "YES";
    else cout << "NO";
}
