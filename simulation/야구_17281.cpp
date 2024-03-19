#include <bits/stdc++.h>

using namespace std;

int n;
int board[55][9];
int order[9]; // 선수들 순서(인덱스)
int temp_a[8] = {1, 2, 3, 4, 5, 6, 7, 8}; // next_permutation 돌릴 것
int ans;
bool isused[4]; // 루에 사람이 있는지 판별, 0루에 있으면(true) 점수 얻음.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    do{
        for (int i = 0; i < 3; i++) {
            order[i] = temp_a[i];
        }
        order[3] = 0;
        for (int i = 3; i < 8; i++){
            order[i + 1] = temp_a[i];
        }

        int j = 0; // 0루타에 서는 선수 번호(order의 인덱스)
        int score = 0; //현재 0점
        for (int i = 0; i < n; i++) {
            fill(isused, isused + 4, false);
            int out  = 0; // 아웃 3번이면 이닝 끝
            while(out < 3) {
                //if(out == 3) break;
                isused[0] = true;
                if(board[i][order[j%9]] == 0) {
                    out++;
                }
                else if(board[i][order[j%9]] == 1){
                    if(isused[3]) {
                        score++;
                        isused[3] = false;
                    }
                    for(int k = 2; k >= 0; k--){
                        if(!isused[k]) continue;
                        isused[k+1] = true;
                        isused[k] = false;
                    }
                }
                else if(board[i][order[j%9]] == 2){
                    if(isused[3]){
                        score++;
                        isused[3] = false;
                    }
                    if(isused[2]) {
                        score++;
                        isused[2] = false;
                    }
                    for(int k = 1; k >= 0; k--){
                        if(!isused[k]) continue;
                        isused[k+2] = true;
                        isused[k] = false;
                    }
                }
                else if(board[i][order[j%9]] == 3){
                    if(isused[3]){
                        score++;
                        isused[3] = false;
                    }
                    if(isused[2]) {
                        score++;
                        isused[2] = false;
                    }
                    if(isused[1]) {
                        score++;
                        isused[1] = false;
                    }
                    isused[3] = true;
                }
                else{
                    score++;
                    if(isused[3]){
                        score++;
                        isused[3] = false;
                    }
                    if(isused[2]) {
                        score++;
                        isused[2] = false;
                    }
                    if(isused[1]) {
                        score++;
                        isused[1] = false;
                    }
                }
                isused[0] = false;
                j++;
            }
        }
        ans = max(ans, score);
    }while(next_permutation(temp_a, temp_a + 8));
    cout << ans;
}