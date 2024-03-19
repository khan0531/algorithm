#include <bits/stdc++.h>

using namespace std;

int n;
int s[25][25];
int mn = 101;

void func(int k){

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }

    vector<int> v; // 0 ~ n-1 중 절반 뽑기 
    for (int i = 0; i < n/2; i++) v.push_back(0); // 0은 한팀
    for (int i = 0; i < n/2; i++) v.push_back(1); // 1은 또 다른 한팀

    do{ //  {0, 0, 1, 1}
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i] == 0 && v[j] == 0) sum += s[i][j];
                else if (v[i] == 1 && v[j] == 1) sum -= s[i][j];
            }
        }
        mn = min(mn, abs(sum));
    }while(next_permutation(v.begin(), v.end()));

    cout << mn;

}