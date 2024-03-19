#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int ans[100002];
    fill(ans, ans + 100001, -1);
    int N, K;
    cin >> N >> K;

    queue<int> q;
    q.push(N);
    ans[N] = 0;
    
    while(ans[K] == -1){
        int cur = q.front();
        q.pop();

        for (int i : {cur + 1, cur - 1, cur * 2 }){
            if (i < 0 || i > 100000) continue;
            if (ans[i] != -1) continue;
            q.push(i);
            ans[i] = ans[cur] + 1;
        }
    }
    cout << ans[K];
}