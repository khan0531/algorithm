#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    cin >> str;

    stack<char> s;
    int ans = 0;
    int a = 1;

    for (int i = 0; i < str.length(); i++){
        if (str[i] == '(') {
            a *= 2;
            s.push(str[i]);
        }
        if (str[i] == '['){
            a *=3;
            s.push(str[i]);
        }
        if (str[i] == ')'){
            if (s.empty() || s.top() != '(')  {
                cout << 0;
                return 0;
            }
            else{
                if (str[i -1] == '(') ans += a;
                s.pop();
                a /= 2;
            }
        }
        if (str[i] == ']'){
            if (s.empty() || s.top() != '[') {
                cout << 0;
                return 0;
            }
            else{
                if (str[i - 1] == '[') ans += a;
                s.pop();
                a /= 3;
            }
        }
    }
    if (s.empty()) cout << ans;
    else cout << 0;
}