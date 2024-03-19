#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 배열 정렬
    sort(arr.begin(), arr.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        int query;
        cin >> query;

        // lower_bound를 사용하여 query 값 찾기
        auto it = lower_bound(arr.begin(), arr.end(), query);

        // lower_bound의 결과가 배열의 끝이 아니며, 찾은 값이 query와 같은 경우
        if (it != arr.end() && *it == query) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}
