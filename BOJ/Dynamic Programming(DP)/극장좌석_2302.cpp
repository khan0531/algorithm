#include <bits/stdc++.h>

using namespace std;

int n, m;
int chair_num[45]; // vip 좌석
vector<int> vip; // vip 좌석 간격
int d[45]; // d[i]는 i칸 일 때 앉을 수 있는 경우의 수
int ans = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> m;
    d[1] = 1;
    d[2] = 2;
    //d[i]는 d[i - 2]에서 두가지 경우가 나올 수 있고, d[i - 1]에서 d[i - 2]뺀 나머지만큼 가능하다.
    for (int i = 3; i <= n; i++) {
        d[i] = d[i - 1] + d[i - 2];
    }
    for (int i = 1; i <= m; i++) {
        cin >> chair_num[i];
        int k = chair_num[i] - chair_num[i - 1];
        if(k <= 1) k = 2;
        vip.push_back(k - 1);
    }
    if(n == chair_num[m]) vip.push_back(1);
    else vip.push_back(n - chair_num[m]);
    
    for(int i : vip){

        ans *= d[i];
    }
    cout << ans;
}