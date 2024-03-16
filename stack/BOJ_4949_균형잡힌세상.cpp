#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        string str;
        getline(cin, str);
        if (str == ".") break;

        stack<char> s;
        string ans;

        for (char c : str){
            if (c == '(' || c == '[') s.push(c);
            else if (c == ')'){
                if (s.empty() || s.top() != '(') {
                    ans = "no";
                    break;
                }
                s.pop();
            }
            else if (c == ']'){
                if (s.empty() || s.top() != '[') {
                    ans = "no";
                    break;
                }
                s.pop();
            }
        }

        if (ans != "no"){
            if (s.empty()) ans = "yes";
            else ans = "no";
        }
        else ans = "no";
        cout << ans << '\n';
    }
}