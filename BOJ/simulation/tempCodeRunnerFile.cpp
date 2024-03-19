#include <bits/stdc++.h>

using namespace std;

int n, l, cnt;
int board[105][105];

bool func(int a[]){
    int k = 1;
    vector<int> v;
    for (int i = 0; i < n - 1; i++) {
        v.push_back(a[i] - a[i + 1]);
    }
    for (int i = 0; i < v.size(); i++){
        if (v[i] == 0) k++;
        else {
            if (v[i] > 1 || v[i] < -1) return false;
            if (v[i] == -1){
                if (k < l) return false;
                else k = 0;
            }
            if (v[i] == 1){
                if (v.size() - i < l) return false;
                if (k < 0) return false;
                k = -l + 1;
            }
        }
    }
    if (k < 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // int a[7] = {2, 2, 3, 2, 2, 2, 3};
    // cout << func(a);

    int a[105] = {};
    int b[105] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[j] = board[i][j];
            b[j] = board[j][i];
        }
        if (func(a))cnt++;
        if (func(b))cnt++;
    }
    cout << cnt;
}
