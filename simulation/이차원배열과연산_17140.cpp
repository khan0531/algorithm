#include <bits/stdc++.h>

using namespace std;

int r, c, k, t;
int a[105][105];
int cnt[1000000];
int r_cnt = 3, c_cnt = 3; // R은 행의 개수, C는 열의 개수

void func1(int i){ // 행에 대해서 실행
    int c_cnt1 = 0;
    fill(cnt, cnt + 100, 0);
    vector<pair<int, int>> v = {};
    for (int j = 0; j < c_cnt; j++) {
        if(a[i][j] == 0) continue;
        cnt[a[i][j]]++;
    }
    for (int j = 0; j < c_cnt; j++) {
        if(a[i][j] == 0) continue;
        v.push_back({cnt[a[i][j]], a[i][j]});
    }
    if(v.size() == 0) return;
    sort(v.begin(), v.end());
    a[i][0] = v[0].second;
    a[i][1] = v[0].first;
    int idxj = 2;
    for (int j = 1; j < 50; j++) {
        if(v[j].second == v[j - 1].second) continue;
        a[i][idxj++] = v[j].second;
        a[i][idxj++] = v[j].first;
    }
    // if (i == 6) cout << "123\n";
    for (int j = 0; j < 100; j++) {
       if(a[i][j] == 0) break;
       c_cnt1++; 
    }
    c_cnt = max(c_cnt, c_cnt1);
}

void func2(int j){ // 열에 대해서 실행
    int r_cnt1 = 0;
    fill(cnt, cnt + 100, 0);
    vector<pair<int, int>> v = {};
    for (int i = 0; i < r_cnt; i++) {
        if(a[i][j] == 0) continue;
        cnt[a[i][j]]++;
    }
    for (int i = 0; i < r_cnt; i++) {
        if(a[i][j] == 0) continue;
        v.push_back({cnt[a[i][j]], a[i][j]});
    }
    if(v.size() == 0) return;
    sort(v.begin(), v.end());
    a[0][j] = v[0].second;
    a[1][j] = v[0].first;
    int idxi = 2;
    for (int i = 1; i < 50; i++) {
        if(v[i].second == v[i - 1].second) continue;
        a[idxi++][j] = v[i].second;
        a[idxi++][j] = v[i].first;
    }
    for (int i = 0; i < 100; i++) {
        if(a[i][j] == 0) break;
        r_cnt1++;
    }
    r_cnt = max(r_cnt, r_cnt1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> k; // r, c는 1부터 시작하는 것 주의한다.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
    int mx = 0;
    // for (int i = 0; i < 4; i++) {
    //     func1(i);
    //     //mx = max(mx, c_cnt);
    // }
    // c_cnt = mx;
    // cout << mx;
    while(t <= 3){
        if(a[r - 1][c - 1] == k) break;
        int mx = 0;
        t++;
        if(t == 101) break;
        cout << '\n';
        cout << "t = " << t << '\n';
        for (int i = 0; i < r_cnt; i++) {
            for (int j = 0; j < c_cnt; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
        if(r_cnt >= c_cnt){
            for (int i = 0; i < r_cnt; i++) {
                func1(i);
                cout << "mx = " << mx << ", c_cnt = " << c_cnt << '\n';
                mx = max(mx, c_cnt);
            }
            c_cnt = mx;
        } else {
            for (int j = 0; j < c_cnt; j++) {
                func2(j);
                mx = max(mx, r_cnt);
            }
            r_cnt = mx;
        }
    }
    
    // if(t == 101) cout << -1;
    // else cout << t;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}