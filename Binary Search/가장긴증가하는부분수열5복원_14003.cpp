#include <bits/stdc++.h>

using namespace std;

int n, ans;
int a[1000005];
int d[1000005];
int id[1000005]; //idx 저장
int pre[1000005]; //바로 이전 idx 불러오는 함수
int idx;

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