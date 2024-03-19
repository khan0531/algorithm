#include <bits/stdc++.h>

using namespace std;

void func(int n) {
    cout << n;
    if (n == 1) return;
    func(n - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    func(n); 
    // func(5)
    // 5 4 3 2 1 
}