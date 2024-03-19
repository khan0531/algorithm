#include <bits/stdc++.h>

using namespace std;
using tup = tuple<int, int, char>;

string s;
int t;
vector<string> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s >> t;
    int n = s.size();
    map<string, int> map;

    for (int i = 0; i < n; i++){
        vector<int> com;
        for (int j = 1; j <= i; j++) com.push_back(0);
        for (int j = 1; j <= n - i; j++) com.push_back(1);
        do {
            vector<tuple<int, int, char>> v;
            for (int k = 0; k < n; k++){
                if (com[k] == 1) v.push_back({k, k, s[k]});
                else v.push_back({k+t+1, k, s[k]});
            }

            sort(v.begin(), v.end());

            deque<char> d;
            for (auto [x, y, z] : v){
                if (z == '-'){
                    if (!d.empty()) d.pop_back();
                    continue;
                }
                d.push_back(z);
            }
            string cur = "";
            while(!d.empty()){
                cur += d.front();
                d.pop_front();
            }
            if (map[cur] != 0) continue;
            if (cur == "") ans.push_back("0");
            ans.push_back(cur);
            map[cur]++;

        } while(next_permutation(com.begin(), com.end()));
    }
    sort(ans.begin(), ans.end());
    for (string cur : ans) cout << cur << " ";
}
