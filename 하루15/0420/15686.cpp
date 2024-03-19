#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;
int board[55][55];
vector<pair<int, int>> home;
vector<pair<int, int>> ch;
int a[20];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) home.push_back({i, j});
            if (board[i][j] == 2) ch.push_back({i, j});
        }
    }

    cnt = ch.size();
    fill(a, a + cnt, 1);
    fill(a, a + m, 0);
    int ans = 10000000;
    do{
        int sum = 0;
        for(auto cur_home : home){
            int dis = 0;
            int min_dis = 1000000;
            for (int i = 0; i < cnt; i++) {
                if (a[i] == 1) continue;
                dis = abs(cur_home.first - ch[i].first) + abs(cur_home.second - ch[i].second);
                min_dis = min(min_dis, dis);
            }
            sum += min_dis;
        }
        ans = min(ans, sum);

    }while(next_permutation(a, a + cnt));

    cout << ans;
}
