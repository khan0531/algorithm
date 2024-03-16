#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    stack<int> s;
    int arr[1000001];

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; //arr = {4, 3, 6, 8, 7, 5, 2, 1} {1, 2, 5, 3, 4}
    }

    string ans = "";
    int i = 1, k = 0;
    s.push(0);

    for (int j = 0; j < n; j++) {
        if (s.top() <= arr[j]){
            while(s.top() < arr[j]) {
            ans += '+';
            s.push(i++);
            }
            ans += '-';
            s.pop();
        }
        if (s.top() > arr[j]){
            ans = "NO";
            break;
        }
    }

    if (ans != "NO"){
        for (char c : ans)
        cout << c << '\n';
    }
    else cout << ans;
}