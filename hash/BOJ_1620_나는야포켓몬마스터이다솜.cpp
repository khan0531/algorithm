#include <bits/stdc++.h>

using namespace std;

int n, m;
bool is_num;
unordered_map<string, int> p;
unordered_map<int, string> p1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        p[s] = i;
        p1[i] = s;
    }
    while(m--){
        is_num = false;
        string s;
        cin >> s;
        for(char c : s){
            if(!isdigit(c)) is_num = false;
            else is_num = true;
        }
        if(is_num) cout << p1[stoi(s)] << '\n';
        else cout << p[s] << '\n';
    }
}