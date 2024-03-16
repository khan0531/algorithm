#include <bits/stdc++.h>

using namespace std;

bool is_used[10];
int arr[10];
int n, m;

// k == m -> 정해진 m개의 수열을 출력하는 함수
// if k < m -> k개의 수열이 정해졌을 때 k + 1 번째 수를 정하는 함수
void func(int k) {
    if (k == m){
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (is_used[i]) continue;

        arr[k] = i;
        is_used[i] = true;
        func(k + 1);
        is_used[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    cin >> n >> m;

    func(0);
}