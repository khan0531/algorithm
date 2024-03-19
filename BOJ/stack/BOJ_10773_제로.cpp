#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;
    cin >> K;

    int sum = 0;

    stack<int> s;

    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;

        if (a !=0 ){
            s.push(a);
            sum += s.top();
        }
        if (a == 0){
            sum -= s.top();
            s.pop();
        }
    }
    cout << sum;
}