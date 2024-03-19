#include <bits/stdc++.h>

using namespace std;

int n, ans;
int a[1'000'005];
int d[1'000'005]; //각 길이를 가질 때의 최소 마지막 값
int id[1'000'005]; //각 길이를 가질 때의 마지막 값의 인덱스
int pre[1'000'005]; //해당 인덱스의 수가 선택되었을 때, 바로 이전에 선택된 수의 인덱스
int idx; // 현재 수 a[i]가 들어갈 수 있는 위치

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        idx = lower_bound(d + 1, d + ans + 1, a[i]) - d;
        d[idx] = a[i];
        id[idx] = i;
        pre[i] = id[idx - 1];
        if(idx == ans + 1) ans++;
    }
    cout << ans <<'\n'; 
    int k = id[ans];
    deque<int> d;
    while(k != 0 ){
        d.push_front(a[k]);
        k = pre[k];
    }
    for(int i : d) cout << i << ' ';

}