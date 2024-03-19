#include <bits/stdc++.h>

using namespace std;

int n, sum1, sum2, ans, cnt1, cnt2;// sum1은 0이하 더함, sum2는 0초과 더함
int a[55];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] <= 0) cnt1++;
        else cnt2++;
    }
    sort(a, a + n);

    //sum1 구하기
    if(cnt1%2 == 1) sum1 = a[cnt1 - 1];
    for (int i = 0; i < cnt1 - 1; i += 2) {
        sum1 += a[i]*a[i + 1];
    }

    //sum2 구하기
    if(cnt2%2 == 1) sum2 = a[cnt1];
    for (int i = n - 1; i > cnt1; i -= 2) {
        if(a[i] == 1 || a[i - 1] == 1) sum2 += (a[i] + a[i - 1]);
        else sum2 += a[i]*a[i - 1];
    }

    cout << sum1 + sum2 << '\n';
}