#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> l(n), r(n), a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 왼쪽에서 오른쪽으로 최대 합 계산
    l[0] = a[0];
    int mx = l[0]; // 전체 최대 합을 저장할 변수
    for (int i = 1; i < n; i++) {
        l[i] = max(a[i], l[i - 1] + a[i]);
        mx = max(mx, l[i]); // 특정 값을 빼지 않았을 때의 최대 합 계산
    }

    // 오른쪽에서 왼쪽으로 최대 합 계산
    r[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        r[i] = max(a[i], r[i + 1] + a[i]);
    }

    // 특정 값을 하나 뺐을 때의 최대 합을 찾음
    for (int i = 1; i < n - 1; i++) {
        mx = max(mx, l[i - 1] + r[i + 1]);
    }

    cout << mx << '\n';

    return 0;
}
