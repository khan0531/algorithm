#include <bits/stdc++.h>

using namespace std;

int n, m, l;
int a[55];
vector<int> len;
int mx;
//m - 1개를 세울 수 있는 최대의 x값을 구하면, x + 1은 m개를 세울 수 있는 최소값이 된다. 그래서 st = mid + 1;
bool check(int x){ // x는 휴개소 사이의 거리이다. 그러므로 x가 커질 수록 세울 수 있는 휴개소 개수는 적어진다. 이 문제에선 휴개소를 m개 세울 수 있는 최소의 x를 구하는 것이다.
    int cnt = 0;
    for(int i : len){
        if(i%x != 0) cnt += i/x;
        else cnt += (i/x - 1);
    }
    return cnt > m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> l;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    if(n == 0) len.push_back(l);
    else{
        len.push_back(a[0]);
        len.push_back(l - a[n - 1]);
    }
    for (int i = 1; i < n; i++) {
        len.push_back(a[i] - a[i - 1]);
    }
    int st = 1;
    int en = 1005;
    while(st < en){
        int mid = (st + en)/2;
        if(check(mid)) st = mid + 1;
        else en  = mid;
    }
    cout << st;
}
