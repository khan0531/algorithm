#include <bits/stdc++.h>

using namespace std;

int n, cnt, ans;
vector<pair<int, int>> cl;

//가장 많이 겹치는 수업의 수 = 곧 필요한 강의실 개수
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int st, en;
        cin >> st >> en;
        cl.push_back({st, 0}); // 수업 시작하는 시간에는 0
        cl.push_back({en, 1}); // 수업 끝나는 시간에는 1로 구분한다.
    }
    sort(cl.begin(), cl.end());
    for(int i = 0; i < 2*n - 1; i++){
        if(cl[i].first == cl[i + 1].first) continue;
        if(cl[i].second == 0) cnt++;
        else cnt--;
        ans = max(ans, cnt);
    }
    cout << ans;
}