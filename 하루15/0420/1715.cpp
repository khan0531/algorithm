#include <bits/stdc++.h>

using namespace std;

int n, card, ans;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while(n--){
        cin >> card;
        pq.push(card);
    }

    int cnt1, cnt2;
    while (pq.size() != 1){
        cnt1 = pq.top();
        pq.pop();
        cnt2 = pq.top();
        pq.pop();

        int sum = cnt1 + cnt2;
        ans += sum;
        pq.push(sum);
    }
    cout << ans;
}
