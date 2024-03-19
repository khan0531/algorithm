#include <bits/stdc++.h>

using namespace std;

string s;
stack<char> c;
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    char pre;
    for (char cur : s){
        if (cur == '(') c.push(cur);
        else {
            c.pop();
            if (pre == '(') ans += c.size();
            else ans += 1;
        }
        pre = cur;
    }
    cout << ans;
}