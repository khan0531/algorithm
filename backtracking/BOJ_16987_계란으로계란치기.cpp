#include <bits/stdc++.h>

using namespace std;


int n;
int s[10]; // 내구도
int w[10]; //무게
int mx;
int cnt;

void func(int k){
    if (k == n || cnt == n -1){
        mx = max(mx, cnt);
        return;
    }

    if(s[k] <=0){
        func(k + 1);
        return;
    }

    for (int i = 0; i < n; i++) { //k번째 계란으로 i번째 계란을 친다.
        if (i == k || s[i] <= 0) continue;
        s[k] -= w[i];
        s[i] -= w[k];
        if(s[k] <= 0) cnt++;
        if(s[i] <= 0) cnt++;
        func (k + 1);
        if(s[k] <= 0) cnt--;
        if(s[i] <= 0) cnt--;
        s[k] += w[i];
        s[i] += w[k];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> w[i];
    }

    func(0);
    cout << mx;
}