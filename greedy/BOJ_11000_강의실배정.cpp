#include <bits/stdc++.h>

using namespace std;

int n, cnt, ans, a, b;
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
    int k = 0;
    for (int i = k; i < 2*n -1; i++) {
        int cur = cl[i].first;
        // 같은 시간에 시작하거나, 끝나는게 존재 할 수 있기 때문에 for문이 아니라, while문 사용
        while(cl[k].first == cur){
            if(cl[k].second == 0) cnt++;
            else cnt--;
            k++;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}