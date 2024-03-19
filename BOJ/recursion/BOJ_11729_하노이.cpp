#include <bits/stdc++.h>

using namespace std;

void func(int N, int start, int end){
    if (N == 1) {
        cout << start << ' ' << end << '\n';
        return;
    }

    int mid = 6 - (start + end);

    func(N - 1, start, mid);
    cout << start << ' ' << end << '\n';
    func(N - 1, mid, end);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    cout << (1 << n) - 1 << '\n';
    func(n, 1, 3);
}
