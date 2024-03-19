#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    long long cnt = 0;
    stack<int> s;
    s.push(0);
    for (int i = 0; i < n; i++) {
        long long high;
        cin >> high; 

        while(high >= s.top()){
            s.pop();
            if (s.empty()) break;
        }
        
        if (s.empty()) s.push(high);
        else{ 
            cnt += s.size();
            s.push(high);
        }
    }
    cout << cnt;
}