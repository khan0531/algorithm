#include <bits/stdc++.h>

using namespace std;

vector<string> parse(string s){

    vector<string> v = {};
    string temp = "";
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == ','){
            v.push_back(temp);
            temp = "";
            continue;
        }
        else temp += s[i];
    }
    if(temp != "") v.push_back(temp);
    return v;
}


// 1 2 3 4 5
string dump1(deque<string> q) {
    string ans = "[";
    int sz = q.size();
    for (int i = 0; i < sz; i++) {
        ans += q.front();
        q.pop_front();
        if (q.empty()) continue;
        ans += ',';
    }
    ans += "]";
    return ans;
}

string dump2(deque<string> q) {
    string ans = "[";
    int sz = q.size();
    for (int i = 0; i < sz; i++) {
        ans += q.back();
        q.pop_back();
        if (q.empty()) continue;
        ans += ',';
    }
    ans += "]";
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;

    while(T--){
        string s, arr; // s= RDD
        int k;
        cin >> s;
        cin >> k >> arr;
        
        deque<string> D; //arr = [1,2,3,4], D = 1 2 3 4
        for (string c : parse(arr)){
            D.push_back(c);
        }
        

        int r = 0, d = 0;
        bool val = true;

        for (char c: s){
           if (c == 'R') r++;
            else if (c =='D'){
                if(D.empty()){ 
                    val = false;
                    break;
                }
                else if (r == 0 || r%2 == 0){
                    D.pop_front();
                    d++;
                }
                else if (r%2 == 1){
                D.pop_back();
                d++;
                }
            }
        }

        if (val){
            if (r == 0 || r%2 == 0) cout << dump1(D) << '\n';
            else cout << dump2(D) << '\n';
        }
        else cout << "error" << '\n'; 
    }
}