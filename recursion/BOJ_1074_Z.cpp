#include <bits/stdc++.h>

using namespace std;

int func(int n, int r, int c) {
    if (n == 0) {
        return 0;
    } 
    int a = 1 << (n - 1);
    if (r < a && c < a) return func(n-1, r, c);
    else if (r < a && c >= a) return func(n - 1, r, c - a) + a * a;
    else if (r >= a && c < a) return func(n - 1, r - a, c) + 2 * a * a;
    else return func(n - 1, r - a, c - a) + 3 * a * a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, c;
    cin >> n >> r >> c;

    cout << func(n, r, c);
}