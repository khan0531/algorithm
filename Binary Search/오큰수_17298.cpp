#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000005];
int nge[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        while(!s.empty() && s.top() <= a[i]) s.pop();
        if(s.empty()) nge[i] = -1;
        else nge[i] = s.top();
        s.push(a[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << nge[i] << ' ';
    }
}