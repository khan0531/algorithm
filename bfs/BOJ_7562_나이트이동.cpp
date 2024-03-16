#include <bits/stdc++.h>

using namespace std;

int dis[301][301];
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    while(N--){
        int I;
        cin >> I;

        for (int i = 0; i < I; i++) {
            fill(dis[i], dis[i] + I, -1);
        }
        
        int startx, starty, endx, endy;
        cin >> startx >> starty;
        cin >> endx >> endy;

        queue<pair<int, int>> q;
        q.push({startx, starty});
        dis[startx][starty] = 0;

        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            for(int dir = 0; dir < 8; dir ++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
                if (dis[nx][ny] != -1) continue;
                q.push({nx, ny});
                dis[nx][ny] = dis[cur.first][cur.second] + 1;
            }
        }
        cout << dis[endx][endy] << '\n';
    }
}