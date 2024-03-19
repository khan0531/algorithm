#include <bits/stdc++.h>

using namespace std;

int board[10][10];
int copy_board[10][10];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
int wall_space;
int safty_space;
int ans;
vector<pair<int, int>> sa; // 처음 안전구역 넣어라
vector<pair<int, int>> vi; // 처음 바이러스 넣어라
int arr[70];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            copy_board[i][j] = board[i][j]; // 원본 복사 해둔다.
            if(board[i][j] == 0) sa.push_back({i, j}); //처음 안전 구역 저장. 0인 지점
            if(board[i][j] == 1) wall_space++;
            if(board[i][j] == 2) vi.push_back({i, j}); // 처음 바이러스가 있는 곳 저장. 2인 지점
        }
    }
    int sz = sa.size(); // 처음 안전구역 사이즈 
    //안전구역 중 벽 세울 세군데 랜덤하게 뽑기.
    fill(arr, arr + sz, 1);
    fill(arr, arr + 3, 0);
    do{
        for (int i = 0; i < sz; i++) {
            if(arr[i] == 0) board[sa[i].first][sa[i].second] = 1;
        }
        queue<pair<int, int>> virus;
        for(auto cur : vi) virus.push(cur);
        int virus_space = 0;

        while(!virus.empty()){
            auto cur = virus.front();
            virus.pop();
            virus_space ++;

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(board[nx][ny] != 0) continue;
                board[nx][ny] = 2;
                virus.push({nx, ny});
            }
        }
        safty_space = n * m - virus_space - wall_space - 3;
        ans = max(ans, safty_space);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = copy_board[i][j];
            }
        }

    }while(next_permutation(arr, arr + sz));
    cout << ans;
}